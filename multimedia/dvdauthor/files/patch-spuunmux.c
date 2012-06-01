--- src/spuunmux.c.orig	2010-05-10 09:27:55.000000000 +0200
+++ src/spuunmux.c	2012-04-27 10:44:31.000000000 +0200
@@ -39,6 +39,7 @@
 #include <netinet/in.h>
 
 #include <png.h>
+#include <zlib.h>
 
 #include "rgb.h"
 #include "common.h"
@@ -610,7 +611,7 @@
         png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
         return -1;
       } /*if*/
-    if (setjmp(png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(png_ptr)))
       {
         png_destroy_write_struct(&png_ptr, &info_ptr);
         fclose(fp);
