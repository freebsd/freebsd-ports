--- splash-png.c~
+++ splash-png.c
@@ -103,7 +103,7 @@ u_char *read_png_file(FILE *stream, u_in
 	if (color_type == PNG_COLOR_TYPE_PALETTE)
 		png_set_palette_to_rgb(png_ptr);
 	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
-		png_set_gray_1_2_4_to_8(png_ptr);
+		png_set_expand_gray_1_2_4_to_8(png_ptr);
 	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha(png_ptr);
 	if (bit_depth == 16)
