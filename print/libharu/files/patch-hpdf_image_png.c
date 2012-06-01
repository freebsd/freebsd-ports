--- src/hpdf_image_png.c.orig	2010-02-08 10:27:51.000000000 +0100
+++ src/hpdf_image_png.c	2012-05-06 06:53:50.000000000 +0200
@@ -21,6 +21,7 @@
 
 #ifndef LIBHPDF_HAVE_NOPNGLIB
 #include <png.h>
+#include <pngpriv.h>
 
 static void
 PngErrorFunc  (png_structp       png_ptr,
