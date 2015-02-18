#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
  int n_storm;
  cin >> n_storm;

  int x_gun,y_gun;
  cin >> x_gun >> y_gun;

  pair<int,int> tmp;
  vector<pair<int,int>> troop_map;

  for (size_t i = 0; i < n_storm; i++)
  {
    cin >> tmp.first >> tmp.second;
    troop_map.push_back(tmp);
  }

  vector<pair<int,int>> alive = troop_map;
  int line_x,line_y;
  int result = 0;
  for (vector<pair<int,int>>::iterator iter_i = troop_map.begin(); iter_i != troop_map.end(); ++iter_i)
  {
    for (vector<pair<int,int>>::iterator iter_j = troop_map.begin(); iter_j != troop_map.end(); ++iter_j)
    {
      bool flag = false;
      if ((iter_i->first - x_gun)*(iter_j->second - y_gun) == (iter_j->first - x_gun)*(iter_i->second - y_gun))
      {
        for (vector<pair<int,int>>::iterator iter_c = alive.begin(); iter_c != alive.end(); ++iter_j)
        {
          if (iter_c->first == iter_j->first && iter_c->second == iter_c->second)
          {
            alive.erase(iter_c);
            flag = true;
            break;
          }
        }
      }
      if (flag == true) {
        result++;
      }
    }
  }
  return 0;
}
