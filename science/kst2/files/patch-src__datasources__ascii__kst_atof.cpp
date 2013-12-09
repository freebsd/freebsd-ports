--- ./src/datasources/ascii/kst_atof.cpp.orig	2012-07-22 13:24:59.000000000 +0000
+++ ./src/datasources/ascii/kst_atof.cpp	2013-12-09 13:59:43.253923430 +0000
@@ -8,6 +8,7 @@
 #include <ctype.h>
 
 #include <QLocale>
+#include <locale.h>
 
 
 #define LOGHUGE 39
