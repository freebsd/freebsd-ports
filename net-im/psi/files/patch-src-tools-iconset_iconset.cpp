--- ./src/tools/iconset/iconset.cpp.orig	2008-03-19 01:24:57.000000000 +0300
+++ ./src/tools/iconset/iconset.cpp	2008-07-30 01:53:45.000000000 +0400
@@ -50,7 +50,7 @@
 #endif
 
 #ifdef ICONSET_ZIP
-#	include "zip.h"
+#	include "psi-zip.h"
 #endif
 
 #include <QApplication>
