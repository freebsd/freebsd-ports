--- mgp.h.orig	2013-12-25 10:03:40.000000000 +0100
+++ mgp.h	2013-12-25 10:05:28.000000000 +0100
@@ -91,7 +91,7 @@
 #endif /* end of VFLIB */
 
 #ifdef FREETYPE
-#include "freetype.h"
+#include "freetype/freetype.h"
 
 #ifndef FREETYPEFONTDIR
 #define FREETYPEFONTDIR	"/usr/local/share/fonts/ttf"
