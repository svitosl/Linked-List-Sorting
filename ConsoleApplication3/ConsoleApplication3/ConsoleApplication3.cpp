// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>
#include <ctime>
#include "windows.h"
#include <iostream>

using namespace std;

struct Node
{
	// указатель на следующий элемент в очереди
	Node *next;
	// значение элемента в очереди
	int value;
};

class Ochered
{
public:
	// Колличество элементов в списке
	int N;
	int i;
	int size = 0;
	int size_1 = NULL;
	// Счетчик колличества операций
	int N_op = 0;
	// указатель на первый элемент 
	Node *head;
	// указатель на хвост очереди
	Node *tail;

	// инициализация очереди
	void Init()
	{
		head = NULL; N_op++;
		// При инициализации head и tail = NULL
		tail = head; N_op++;
	}

	// добавление элемента в начало очереди, x - значение этого элемента
	void Add(int x)
	{
		// создание нового элемента
		Node *node = new Node; N_op+=3;
		// в поле next данного элемента записывается NULL
		node->next = NULL; N_op+=2;
		// в поле value записывается значение ячейки очереди int
		node->value = x; N_op+=2;
		// после инициализации и при создании первого элемента мы проходим по ветке else
		if (tail != NULL)
		{ N_op++;
			/* добавление элемента через хвост в очереди,
			tail указывает на первый элемент в очереди перед добавляемым
			в поле next первого элемента записывается адрес нового первого элемента*/
			tail->next = node; N_op+=2;
			// tail начинает указывать на новый элемент в очереди
			tail = node; N_op++;
		}
		else
		{ N_op++;
			// хвост указывает на первый элемент в очереди
			tail = node; N_op++;
			// голова указывает на первый элемент в очереди
			head = tail; N_op++;
		}
		size++; N_op+=2;
	}

	// проверка очереди на пустоту
	bool Isempty() 
	{ N_op++;
		//true, если head = NULL; false, если head указывает на какой-либо элемент в очереди
		return head == NULL;
	}

	// удаление элемента из конца очереди
	int Del()
	{
		int val = NULL; N_op++;
		// если очередь не пуста
		if (Isempty() != 1)
		{ N_op++;
			// создаем указатель на структуру
			Node *tmp;
			//  в указателюь tmp кладем ссылку на next предпоследнего элемента в очереди 
			tmp = head->next; N_op+=2;
			// в val записываем значение последнего элемента в очереди
			val = head->value; N_op+=2;
			// удаляем объект по указателю head (последний элемент в очереди)
			delete head;
			// head начинает указывать на предпоcледний элемент в очереди (последний удален)
			head = tmp; N_op++;
			
			// После удаления последнего элемента из очереди происходит повторная инициализация
			if (Isempty() == 1)
			{ N_op++;
				Init();
			}
			size--; N_op+=2;
			// возвращаем значение последнего элемента в очереди
			return val;
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;

	}

	// получение значения из конца очереди
	int Value() 
	{
		// если очередь не пуста
		if (Isempty() != 1)	
		{ N_op+=2;
			// через указатель head получить значение value последнего элемента в очереди
			return head->value;
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;
	}

};

// Класс наследник
class Numbers : public Ochered
{
	public:
	// получение значения из списка, x - номер элемента в списке
	int get(int x)
	{
		// если очередь не пуста
		if (Isempty() != 1)
		{ N_op++;
			size_1 = size; N_op++;
			int val1 = NULL; N_op++;

			/* Перебор всех значений в списке*/ N_op++;
			for (int i = 1; i < size_1 + 1; i++)
			{
				if (i == x)
				{ N_op++;
					// Когда i доходит до номера получаемого элемента, то в val записывается значение данного элемента
					val1 = Value();	N_op++;
				}

				// Перебор начинается только в случае если x не равен нулю
				if (x != 1)
				{ N_op++;
				// Вначале элемент удаляется из конца очереди, и сразу же добавляется в начало очереди, и так в цикле пока не восстановится первоначальное состояние очереди
				Add(Del());
				}
				else
				{ N_op++;
					// В противном случае сразу выходим из цикла for
					break;
				}
			}
			// Возвращается значение элемента под номером x из очереди
			return val1;
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;
	}

	// установка значения элемента в списке, x - номер элемента в списке, y - значение элемента в списке
	void set(int x, int y) 
	{
		// если очередь не пуста
		if (Isempty() != 1)
		{ N_op++;
			if (x <= size)
			{ N_op++;
				size_1 = size; N_op++;
				N_op++;
				for (int i = 1; i < size_1 + 1; i++)
				{
					if (i == x)
					{ N_op++;
						// Запись значения y в список
						head->value = y; N_op+=2;
					}

					if (x != 1)
					{ N_op++;
						Add(Del());
					}
					else
					{ N_op++;
						break;
					}
				}
			}
			// Если элемент устанавливается за пределы изначального списка
			else
			{ N_op++;
				if (x == size + 1)
				{ N_op+=2;
					//Если номер элемента в списке на 1 больше размера очереди, значит элемент добавляется в начало очереди
					Add(y);
				}
				else
				{ N_op+=2; N_op++;
					for (i = size + 1; i < x; i++)
					{
						// В противном случае очередь заполняется нулями
						Add(0);
					}
					Add(y);
				}

			}
			
		}
		else { cout << "Очередь пуста!" << endl; }
	}

	void sort(int N)
	{
			int s, f, d, i, j, g, k, p;
			s = 1; N_op++;

			do
			{
				s = 1 - s; N_op+=2;
				d = 1; N_op++;
				f = 1; N_op++;

				if (s == 0)
				{ N_op++;
					i = 1; N_op++;
					j = N; N_op++;
					k = N + 1; N_op+=2;
					g = 2 * N; N_op+=2;
				}
				else
				{ N_op++;
					i = N + 1; N_op+=2;
					j = 2 * N; N_op+=2;
					k = 1; N_op++;
					g = N; N_op++;
				}
				while (i != j)//
				{ N_op++;
					// if(K[i]<K[j])
					if (get(i) > get(j))
					{ N_op++;
						// R[k] = R[j];
						set(k, get(j));
						k = k + d; N_op+=2;
						j = j - 1; N_op+=2;

						// if (!(K[j+1]<=K[j]))
						if (get(j + 1) <= get(j))
						{
						 N_op+=2;
						}
						else
						{ N_op+=2;
							do
							{
								// R[k]=R[i];
								set(k, get(i));
								k = k + d; N_op+=2;
								i = i + 1; N_op+=2; N_op+=2;
							}
							// while(!K[i-1]>=K[i]);
							while (get(i - 1) < get(i));

							f = 0; N_op++;
							d = -d; N_op++;
							p = k; N_op++;
							k = g; N_op++;
							g = p; N_op++;
						}
					}
					else
					{ N_op++;
						// R[k]=R[i];
						set(k, get(i));
						k = k + d; N_op+=2;
						i = i + 1; N_op+=2;
						// if(K[i-1]<=K[i])
						if (get(i - 1) <= get(i))
						{
						 N_op+=2;
						}
						else
						{ N_op+=2;
							do
							{
								// R[k] = R[j];
								set(k, get(j));
								k = k + d; N_op+=2;
								j = j - 1; N_op+=2; N_op+=2;
							}
							// while(K[j+1]>=K[j]);
							while (get(j + 1) < get(j));
							f = 0; N_op++;
							d = -d; N_op++;
							p = k; N_op++;
							k = g; N_op++;
							g = p; N_op++;

						}
					}
				}
				//R[k]=R[i];
				set(k, get(i)); N_op++;
			} while (f != 1);


			if (s == 0)
			{ N_op+=2;
				for (int i = 1; i <= N; i++)
				{ N_op++;
					// R[i] = R[i+n];
					set(i, get(i + N));
				}

			}

			size_1 = size; N_op+=2;
			for (int i = 1; i <= size_1; i++)
			{
				if (i <= size / 2)
				{ N_op+=2;
					Add(Del());
				}
				else
				{ N_op+=2;
					Del();
				}
			}
	}

	///////////////////////////Отладка//////////////////////////////////
	void TMP_Params()
	{
		int i, j;
		char number;
		do
		{
			cout << "1. Добавить элемент Add()" << endl;
			cout << "2. Удалить элемент Del()" << endl;
			cout << "3. Сортировать список sort()" << endl;
			cout << "4. Получить значение на выходе Value()" << endl;
			cout << "5. Установить значение в любою ячейку очереди set()" << endl;
			cout << "6. Вывести значение из любой ячейки очереди get()" << endl;
			cout << "7. Вывести на экран всю очередь" << endl;
			cout << "8. Вывести длинну очереди size" << endl;
			cout << "9. Вывести колличество операций N_op" << endl;
			cout << "0. Выйти\n\n";
			cout << "Номер команды > ";
			cin >> number;
			switch (number)
			{
			case '1':
				cout << "Введите число: ";
				cin >> i;
				Add(i);
				break;
				//-----------------------------------------------
			case '2':
				cout << "Удалилось число: " << Del() << endl;
				break;
				//-----------------------------------------------
			case '3':
				sort(size);
				cout << "Массив отсортирован" << endl;
				break;
				//-----------------------------------------------
			case '4':
				cout << "Значение на выходе: " << Value() << endl;
				break;
				//-----------------------------------------------
			case '5':
				cout << "Введите номер элемента в списке: ";
				cin >> i;
				cout << "Введите значение элемента в списке: ";
				cin >> j;
				set(i, j);
				break;
				//-----------------------------------------------
			case '6':
				cout << "Введите номер элемента в списке: ";
				cin >> i;
				cout << "Значение элемента: " << get(i) << endl;
				break;
				//-----------------------------------------------
			case '7':
				cout << "Очередь:\n" << endl;
				for (int i = 1; i < size + 1; i++)
				{
					cout << get(i) << " | ";
				}
				cout << "\n" << endl;
				break;
				//-----------------------------------------------
			case '8':
				cout << "Длинна очереди: " << size << endl;
				break;
				//-----------------------------------------------
			case '9':
				cout << "Колличество операций: " << N_op << endl;
				cout << "Обнулить счетчик колличества операций (y)?";
				char qu;
				cin >> qu;
				if (qu == 'y')
				{
					N_op = 0;
					cout << "Счетчик колличества операций обнулен" << endl;
				}
				else
				{
					cout << "Счетчик будет суммироваться" << endl;
				}
				break;
				//-----------------------------------------------
			case '0': break;
			default: cout << endl << "Команда не определена\n";
				break;
			}
			system("pause");
			system("cls");
		} while (number != '0');
	}
	////////////////////////////////////////////////////////////////////////////
};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	// Схема эксперимента
	// Инициализация очереди и заполнение хранилища ключей
	int i, t_s, t_f;
	// Хранилище ключей
	int Key[3000]; 
	int N = 300;
	Numbers list;
	list.Init();

	list.Add(354);
	list.Add(123);
	list.Add(28);
	list.Add(717);
	list.Add(672);
	list.Add(128);
	list.Add(126);
	list.Add(49);
	list.Add(622);
	list.Add(685);
	list.TMP_Params();


	/*for (i = 0; i < 3000; i++)
	{
		// Заполнение хранилища ключей случайными числами до 1000
		Key[i] = rand() % 999;
	}

	for (i = 0; i < 10; i++)
	{
		for (int z = N - 300; z < N; z++)
		{
			list.Add(Key[z]);
		}

		t_s = GetTickCount();
		list.sort(N);
		t_f = GetTickCount();

		cout << "Номер сортировки: " <<  i + 1 << " Колличество отсортированных элементов: " << N << " Время сортировки (ms): " << t_f - t_s << endl;
		// Шаг в 300 элементов
		N = N + 300;

	}*/

	return 0;
}
