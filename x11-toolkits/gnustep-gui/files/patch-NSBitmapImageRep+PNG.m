--- Source/NSBitmapImageRep+PNG.m.orig	2009-02-17 00:23:41.000000000 +0100
+++ Source/NSBitmapImageRep+PNG.m	2012-04-27 18:54:35.000000000 +0200
@@ -33,9 +33,11 @@
 #if HAVE_LIBPNG
 
 #ifdef HAVE_LIBPNG_PNG_H
-#include <libpng/png.h>
+#include <png.h>
+#include <pngpriv.h>
 #else
 #include <png.h>
+#include <pngpriv.h>
 #endif
 
 #include <Foundation/NSData.h>
