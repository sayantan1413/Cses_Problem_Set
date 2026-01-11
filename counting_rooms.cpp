#include<iostream>
#include<vector>
#include <string>
using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void dfs(vector<string>& grid, vector<vector<bool>>& visited, int x,  int y, int n, int m) {
	visited[x][y] = true;

	for (int i=0;i<4;++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!visited[nx][ny] && grid[nx][ny] == '.') {
				dfs(grid, visited, nx, ny, n, m);
			}
		}
	}
}

int main() {
	int n, m;
	int rooms = 0;
	cin >> n >> m;
	vector<string> grid(n);
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i=0;i<n;++i) {
		cin >> grid[i];
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (!visited[i][j] && grid[i][j] == '.') {
				rooms++;
				dfs(grid, visited, i, j, n, m);
			}
		}
	}
	cout << rooms << "\n";
	return 0;
}