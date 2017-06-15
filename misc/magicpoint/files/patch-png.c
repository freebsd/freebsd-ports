--- image/png.c.orig	2001-04-11 08:37:00 UTC
+++ image/png.c
@@ -86,7 +86,7 @@ pngLoad(fullname, name, verbose)
 		return NULL;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 		fclose(fp);
 		return NULL;
@@ -134,7 +134,7 @@ pngLoad(fullname, name, verbose)
 	} 
 
 	if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8){
-		png_set_gray_1_2_4_to_8(png_ptr);
+		png_set_expand_gray_1_2_4_to_8(png_ptr);
 	}
 
 	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)){
