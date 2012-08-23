--- ./style/qt_settings.c.orig	2012-04-24 21:19:54.000000000 +0000
+++ ./style/qt_settings.c	2012-08-23 11:13:08.651930973 +0000
@@ -46,6 +46,9 @@
 
 #define strcmp_i(A, B) strncmp_i(A, B, -1)
 
+#include "getline.h"
+#include "getline.c"
+
 QtCPalette qtcPalette;
 Options    opts;
 
