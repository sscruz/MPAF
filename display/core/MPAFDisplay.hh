#ifndef _MPAFDisplay_
#define _MPAFDisplay_

#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>
#include <math.h>
#include <sstream>


#include "display/core/AnaConfig.hh"
#include "display/core/Display.hh"
#include "tools/src/AnaUtils.hh"
#include "tools/src/Dataset.hh"
#include "tools/src/DataBaseManager.hh"
#include "tools/src/HistoManager.hh"


class MPAFDisplay {

  //===== variables =====

private:

  bool _recompute;

  vector<string> _dsnames;

  string _currentObs;

  string _ids; //the current dataset
  int _inds; //the current dataset
  float _w; //the current global weight

  bool _isData;

  HistoManager* _hm;
  DataBaseManager* _dbm;
  AnaUtils* _au;

public:

  AnaConfig anConf;

  Display dp;

  //===== functions ====

private:

  void reset();
  void configure();


  void setNumbers();
  void setHistograms();

  vector<string> split(const string& s, char delim);
  string findDiff(const string& s1, const string& s2,
		  char delim, size_t& bl, size_t& bh);
  void readStatFile(string filename, string ctag, int& icat);

public:

  MPAFDisplay();
  ~MPAFDisplay();

  //void unlockStatus();

  void refresh();

  
  void doPlot();


  void makeDataCard(string dirname, string categ = "global", string cname = "");

  void getStatistics(string categ="global");
  void drawStatistics(string categ="global", string cname="");

  void savePlot(string path, string advname="");
  void producePlots(string path);

  void saveHistos(std::string);

  void getYield(string ds, string lvl);

  void drawEfficiencies(string o1);
  void drawROCcurves(string o1);
  void multiROCcurves();


  void drawRatio(string o1, string o2 );
  void drawResiduals(string o1);
  void drawSignificance(string o1);
  void drawCumulativePlots(string o1);
  void drawDetailSyst(bool cumul);

  void getIntegral(float x1, float x2, float y1=0, float y2=1000000);
  
  void saveDataMCRatio(string fname,string hname);



  ClassDef(MPAFDisplay,0)

};


#endif
