--- src/gui_main.cc.orig	Thu Dec 19 00:41:05 2002
+++ src/gui_main.cc	Thu Apr  8 22:41:14 2004
@@ -830,8 +830,8 @@
   */
   ifstream infile(filename.c_str(), ios::in);
   map<string, string> guiInfoMap;
-  if(infile.bad()) return false;
-  
+  if(!infile.is_open() || infile.bad()) return false;
+
   if(infile.eof()) return false;
   while(!infile.eof()) {
     string line;
