--- src/pslib.c.orig	2010-08-27 08:20:08.000000000 +0200
+++ src/pslib.c	2010-08-27 08:20:29.000000000 +0200
@@ -4600,7 +4600,7 @@
 
 		/* Expand grayscale images to the full 8 bits from 1, 2, or 4 bits/pixel */
 		if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
-			png_set_gray_1_2_4_to_8(png_ptr);
+			png_set_expand_gray_1_2_4_to_8(png_ptr);
 
 		png_read_update_info(png_ptr, info_ptr);
 #else
