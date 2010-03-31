--- src/media_tools/img.c.orig	2010-03-31 10:03:24.806360005 +0000
+++ src/media_tools/img.c	2010-03-31 10:05:39.430477556 +0000
@@ -551,7 +551,7 @@
 	/* Allocate/initialize the image information data.  REQUIRED */
 	info_ptr = png_create_info_struct(png_ptr);
 	if (info_ptr == NULL) {
-		png_destroy_write_struct(&png_ptr,  png_infopp_NULL);
+		png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
 		return GF_IO_ERR;
 	}
 	
