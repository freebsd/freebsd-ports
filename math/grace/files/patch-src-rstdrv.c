--- src/rstdrv.c.orig	2004-07-03 22:47:46.000000000 +0200
+++ src/rstdrv.c	2012-04-27 20:54:10.000000000 +0200
@@ -54,6 +54,7 @@
 
 #ifdef HAVE_LIBPNG
 #  include <png.h>
+#  include <zlib.h>
 #endif
 
 #ifndef NONE_GUI
@@ -885,7 +886,7 @@
         return;
     }
 
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
         png_destroy_write_struct(&png_ptr, &info_ptr);
         return;
     }
