--- src/HistoryWindow.cc.orig	Wed Oct  2 00:32:00 2002
+++ src/HistoryWindow.cc	Thu Apr  8 22:41:14 2004
@@ -479,7 +479,7 @@
 {
   ifstream infile(filename.c_str(), ios::in);
 
-  if(infile.bad()) return false;
+  if(!infile.is_open() || infile.bad()) return false;
   int count = 0;
   while(!infile.eof() && count < maxHistory) {
     string line;
