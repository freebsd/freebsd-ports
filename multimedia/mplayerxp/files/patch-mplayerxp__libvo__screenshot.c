--- mplayerxp/libvo/screenshot.c.orig	2006-11-30 07:28:10.000000000 +0100
+++ mplayerxp/libvo/screenshot.c	2012-05-06 20:04:09.000000000 +0200
@@ -20,6 +20,7 @@
 #include <libpng/png.h>
 #else
 #include <png.h>
+#include <zlib.h>
 #endif
 #endif
 
@@ -67,7 +68,7 @@
        return png;
     }
     
-    if (setjmp(png.png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png.png_ptr))) {
 	MSG_V("PNG Internal error!\n");    
         png_destroy_write_struct(&png.png_ptr, &png.info_ptr);
         fclose(png.fp);
