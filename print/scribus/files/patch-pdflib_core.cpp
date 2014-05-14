--- scribus/pdflib_core.cpp.orig	2013-01-20 06:15:07.000000000 +0400
+++ scribus/pdflib_core.cpp	2013-09-14 22:18:16.618750736 +0400
@@ -83,7 +83,7 @@
 #include "util_math.h"
 #include "util_ghostscript.h"
 
-using namespace std;
+// using namespace std;
 
 #if defined(_WIN32)
 #undef GetObject
@@ -154,7 +154,7 @@
 	delete progressDialog;
 }
 
-static inline QString FToStr(double c)
+static QString FToStr(double c)
 {
 	return QString::number(c, 'f', 5);
 };
