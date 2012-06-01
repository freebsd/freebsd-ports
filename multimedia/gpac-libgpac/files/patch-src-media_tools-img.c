--- src/media_tools/img.c.orig	2008-12-01 18:39:36.000000000 +0100
+++ src/media_tools/img.c	2012-04-24 23:00:42.000000000 +0200
@@ -33,6 +33,7 @@
 
 /*include png.h before setjmp.h, otherwise we get compilation errors*/
 #include <png.h>
+#include <pngpriv.h>
 
 #endif /*GPAC_HAS_PNG*/
 
@@ -399,7 +400,7 @@
 }
 static void user_error_fn(png_structp png_ptr,png_const_charp error_msg)
 {
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 GF_EXPORT
@@ -424,7 +425,7 @@
 		png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
 		return GF_IO_ERR;
 	}
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		png_destroy_info_struct(png_ptr,(png_infopp) & info_ptr);
 		png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
 		return GF_IO_ERR;
@@ -551,7 +552,7 @@
 	/* Allocate/initialize the image information data.  REQUIRED */
 	info_ptr = png_create_info_struct(png_ptr);
 	if (info_ptr == NULL) {
-		png_destroy_write_struct(&png_ptr,  png_infopp_NULL);
+		png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
 		return GF_IO_ERR;
 	}
 	
