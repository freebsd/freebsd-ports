--- netmap/netmap.c.orig
+++ netmap/netmap.c
@@ -1,4 +1,4 @@
-#include <strstream>
+#include <sstream>
 #include <iostream>
 #include <fstream>
 
@@ -18,7 +18,7 @@
 Dbgfile dbgs;
 int cdb = 1;
 
-static void copy_line(strstream& os, istream& inf) 
+static void copy_line(stringstream& os, istream& inf) 
 {
     string result;
 
@@ -67,7 +67,7 @@
     int nr_hops = 0;
     int invalid_hosts_found = 0;
     while(inf && !inf.eof()) {
-	strstream line;
+	stringstream line;
 	copy_line(line, inf);
 	
 	if(max_hops && ++nr_hops > max_hops) {
