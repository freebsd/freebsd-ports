--- ./plugins/png/ir_png.c.orig	2009-06-11 19:25:29.000000000 +0400
+++ ./plugins/png/ir_png.c	2010-05-31 19:38:31.000000000 +0400
@@ -126,7 +126,7 @@
         bits = 16;
         }
       if(bit_depth < 8)
-        png_set_gray_1_2_4_to_8(png->png_ptr);
+        png_set_expand_gray_1_2_4_to_8(png->png_ptr);
       if (png_get_valid(png->png_ptr, png->info_ptr, PNG_INFO_tRNS))
         {
         png_set_tRNS_to_alpha(png->png_ptr);
