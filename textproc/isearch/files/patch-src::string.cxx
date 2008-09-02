--- src/string.cxx.orig	2000-10-31 01:22:09.000000000 -0500
+++ src/string.cxx	2008-08-10 20:55:59.000000000 -0500
@@ -45,9 +45,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <fstream.h>
 #include <ctype.h>
 #include <sys/stat.h>
+#include <fstream>
+using namespace std;
 
 #ifdef UNIX
 #include <unistd.h>
@@ -574,7 +575,7 @@
 
 // can this be const STRING& ?
 ostream& operator<<(ostream& os, const STRING& str) {
-  os.write(str.Buffer, str.Length);
+  os.write((char*)str.Buffer, str.Length);
   return os;
 }
 
