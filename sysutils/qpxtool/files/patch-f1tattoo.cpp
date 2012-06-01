--- console/f1tattoo/f1tattoo.cpp.orig	2009-11-25 08:55:44.000000000 +0100
+++ console/f1tattoo/f1tattoo.cpp	2012-05-09 13:18:22.000000000 +0200
@@ -18,6 +18,7 @@
 
 #ifdef USE_LIBPNG
 #include <png.h>
+#include <pngpriv.h>
 #endif
 
 #include "version.h"
