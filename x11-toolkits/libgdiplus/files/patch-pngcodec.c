--- src/pngcodec.c.orig	2009-06-08 19:30:15.000000000 +0200
+++ src/pngcodec.c	2010-03-28 15:27:01.000000000 +0200
@@ -352,7 +352,7 @@
 						info_ptr->palette[i].blue,
 						info_ptr->palette[i].green,
 						info_ptr->palette[i].red,
-						info_ptr->trans[i]); /* alpha */
+						info_ptr->trans_alpha[i]); /* alpha */
 			}
 		}
 
@@ -418,7 +418,7 @@
 		}
 
 		if ((color_type == PNG_COLOR_TYPE_GRAY) && (bit_depth < 8)) {
-			png_set_gray_1_2_4_to_8(png_ptr);
+			png_set_expand_gray_1_2_4_to_8(png_ptr);
 		}
 
 		if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
