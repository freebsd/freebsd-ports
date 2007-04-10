--- src/dvbcut.h~	Thu Dec 15 20:24:42 2005
+++ src/dvbcut.h	Mon Apr  9 16:55:43 2007
@@ -52,14 +52,15 @@
   int busy;
   int viewscalefactor;
   int currentaudiotrack;
-  std::vector<std::pair<std::string,std::string> > recentfiles;
 
 protected:
   //   QPixmap getpixmap(int picture, bool allgop=false);
   void exportvideo(const char *fmt);
   void addtorecentfiles(const std::string &filename, const std::string &idxfilename=std::string());
-  void loadrecentfilesfromsettings();
   void setviewscalefactor(int factor);
+
+  // special event handling (mouse wheel)
+  bool eventFilter(QObject *watched, QEvent *e);
 
 public:
   ~dvbcut();
