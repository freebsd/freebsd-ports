--- ./src/dialogs/similarcategoriesdialog.cpp.orig	2011-02-15 21:13:12.000000000 -0500
+++ ./src/dialogs/similarcategoriesdialog.cpp	2011-02-15 21:13:27.000000000 -0500
@@ -202,7 +202,6 @@
 /*****************************************************/
 
 #include <stdlib.h>
-#include <malloc.h>
 #include <string.h>
 int levenshtein_distance(const char *s,const char*t);
 int minimum(int a,int b,int c);
