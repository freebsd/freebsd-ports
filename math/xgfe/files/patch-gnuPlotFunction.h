diff -u gnuPlotFunction.h.orig gnuPlotFunction.h
--- gnuPlotFunction.h.orig	Sat Mar 21 04:30:33 1998
+++ gnuPlotFunction.h	Thu Oct 30 21:42:04 2003
@@ -27,7 +27,9 @@
 #define gnuPlotFunction_included
 
 #include <string>
-#include <iostream.h>
+#include <iostream>
+
+using namespace std;
 
 class gnuPlotFunction
 {
