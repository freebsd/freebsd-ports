--- modules/file/pixmap.c.orig	2012-01-09 08:43:04.000000000 +0100
+++ modules/file/pixmap.c	2012-05-09 13:09:36.000000000 +0200
@@ -40,6 +40,7 @@
 
 #ifdef HAVE_PNG
 #include <png.h>
+#include <zlib.h>
 #endif
 
 #include <libgwyddion/gwymacros.h>
