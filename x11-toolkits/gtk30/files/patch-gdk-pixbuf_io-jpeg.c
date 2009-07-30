--- gdk-pixbuf/io-jpeg.c.orig	2009-07-30 00:54:14.000000000 -0400
+++ gdk-pixbuf/io-jpeg.c	2009-07-30 00:54:27.000000000 -0400
@@ -922,7 +922,7 @@ gdk_pixbuf__jpeg_image_load_increment (g
 				}
 			}
 			
-			for (cinfo->scale_denom = 2; cinfo->scale_denom <= 8; cinfo->scale_denom *= 2) {
+			for (cinfo->scale_denom = 2; cinfo->scale_denom <= 16; cinfo->scale_denom *= 2) {
 				jpeg_calc_output_dimensions (cinfo);
 				if (cinfo->output_width < width || cinfo->output_height < height) {
 					cinfo->scale_denom /= 2;
