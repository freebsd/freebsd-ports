--- plugins/png/ir_png.c.orig	2011-11-17 15:55:16.000000000 +0100
+++ plugins/png/ir_png.c	2011-11-17 15:55:29.000000000 +0100
@@ -133,7 +133,6 @@
       png_set_expand_gray_1_2_4_to_8(png->png_ptr);
 #endif
 
-        png_set_gray_1_2_4_to_8(png->png_ptr);
       if (png_get_valid(png->png_ptr, png->info_ptr, PNG_INFO_tRNS))
         {
         png_set_tRNS_to_alpha(png->png_ptr);
