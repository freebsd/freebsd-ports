--- Xrgraph.cpp.orig	Wed Mar 29 14:13:46 2000
+++ Xrgraph.cpp	Fri Dec 19 13:37:03 2003
@@ -18,9 +18,13 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
-#include <iostream.h>
+#include <iostream>
 #include <assert.h>
 
+using std::cout;
+using std::cerr;
+using std::endl;
+
 #define MAXSHORT 0xFFFF
 
 #ifdef HPPA
@@ -82,8 +86,8 @@
   exit(err);}
 
 #ifdef FREEFEM
-#include <fstream.h>
-#include <new.h>
+#include <fstream>
+#include <new>
 
 void out_of_memory ();
 void myexit(int );
