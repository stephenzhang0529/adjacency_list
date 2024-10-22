#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

//问题：给定一个有向图，找出从某个顶点出发可以到达的所有节点。
class Graph {
private:
	int sum_point;// 顶点的总数量
	vector< list<int>> adjlist;// 邻接表

public:
	//构造函数，初始化图的顶点数量和邻接表
	Graph(int point)
	{
		this->sum_point = point;
		adjlist.resize(sum_point);// 调整邻接表的大小
	}
	//添加边，给point点添加一条边指向endpoint点
	void addedge(int point, int endpoint)
	{
		//先检查边是否已存在，避免重复
		for (auto it = adjlist[point].begin(); it != adjlist[point].end(); it++)
		{
			if (*it == endpoint)
			{
				return;
			}
		}
		adjlist[point].push_back(endpoint);
	}
	//打印图的邻接表
	void printgraph()
	{
		for (int i = 0; i < sum_point; i++)
		{
			cout << "顶点 " << i << " -> ";
			for (auto index : adjlist[i])
			{
				cout << index << " ";
			}
			cout << endl;
		}
	}
	void BFS(int startpoint)
	{
		//用于判断某点是否已经来过
		vector<bool>visited(sum_point, false);
		visited[startpoint] = true;
		queue<int>q;//用于存储未处理数据
		q.push(startpoint);
		cout << "从顶点 " << startpoint << " 出发可以访问到的节点: ";

		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			cout << current << " ";
			for (auto index : adjlist[current])
			{
				if (!visited[index])
				{
					visited[index] = true;
					q.push(index);//将未访问的顶点加入队列
				}
			}
		}
		cout << endl;
	}
};

int main()
{
	Graph example(11);

	example.addedge(0, 1);
	example.addedge(0, 1);//重复添加检验
	example.addedge(0, 2);
	example.addedge(1, 3);
	example.addedge(1, 4);
	example.addedge(3, 6);
	example.addedge(4, 5);
	example.addedge(4, 2);
	example.addedge(4, 9);
	example.addedge(6, 7);
	example.addedge(6, 8);
	example.addedge(9, 10);

	example.printgraph();
	example.BFS(0);

	return 0;
}