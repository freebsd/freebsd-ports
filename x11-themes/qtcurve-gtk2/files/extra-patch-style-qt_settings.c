--- ./style/qt_settings.c.orig	2011-01-03 00:41:06.000000000 +0300
+++ ./style/qt_settings.c	2011-01-15 21:01:39.529481980 +0300
@@ -35,6 +35,8 @@
 #include <dirent.h>
 #include <errno.h>
 #include <locale.h>
+#include "getline.h"
+#include "getline.c"
 
 QtCPalette qtcPalette;
 Options    opts;
