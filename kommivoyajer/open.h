#pragma once
#include <glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

const int maxSize = 15;
extern int WinW;
extern int WinH;
struct vertCoord
{
	int x, y;
};

class Graph
{
private:
	vector<int> vertList;															//вектор вершин
	int adjMatrix[maxSize][maxSize];												//массив матрицы
public:
	Graph();
	~Graph();
	bool IsEmpty();
	bool IsFull();

	int getVertText(int i) { return vertList[i]; }                                 //вершина                           
	vector<int> getVertexList() { return  vertList; }                                //вектор вершин                        
	int getAdjMatrixElem(int i, int j) { return adjMatrix[i][j]; }                 //элемент матрицы    
	void setEdgeZero(int i, int j) { adjMatrix[i][j] = 0; adjMatrix[j][i] = 0; }   //зануляем элемент матрицы
	int GetAmountVerts() { return vertList.size(); }                               //вершины графа
	int GetVertPos(const int& vertex);		                                       //позиция вершины в векторе
	int GetAmountEdges();                                                          //количество ребер
	void InsertVertex(const int& vertex);					                       //добавить вершину
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);	       //добавить ребро с указанным весом, между введенными городами
	void Print();		                                                           //вывод матрицы
	void eraseLastVertex();                                                          //удалить вершину, которая идет последней в векторе
	void eraseEdge(const int& vertex1, const int& vertex2);                        //удалить ребро между введенными городами
	void drawGraph();                                                              //отрисовка графа
};
extern Graph graph;		                                                           //создание объекта   

int** Make_Matrix();	                                                         //создание матрицы
int* Find_Min(int* line, int n);	                                             //ищем наименьший элемент в строке
void Print_Matrix(int** matrix);		                                         //вывод матрицы
int** Reduct_Matrix(int** oldmatrix);		                                     //редуцируем матрицу
int** Rebuild_Matrix(int** oldmatrix);
void Print_Result();                                                             //Вывод результата задачи

void drawButton1();
void drawButton2();
void drawButton3();
void drawButton4();

void drawCircle(int x, int y, int R);
void drawOutlineCircle(int x, int y, int R);
void drawText(int nom, int x1, int y1);
void drawLine(int text, int x0, int y0, int x1, int y1);
void drawVertex(int n);

void makeGraph();
void setCoords(int i, int n);

bool Salesman_Check(int** matrix);
int Circle_Check(int x, int y);
void Button_Check(int x, int y);

void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y);
void reshape(int w, int h);
void display();
