--- src/png.c.orig	1998-11-21 15:55:13.000000000 +0100
+++ src/png.c	2010-09-15 07:51:20.000000000 +0200
@@ -76,10 +76,16 @@
     return fp;
 }
 
+static Pixmap rep_fail(const char *e) {
+	ArtTextAddLine(main_widgets.text, e, ascii_font->body_font,
+		global.alert_pixel);
+	return None;
+}
+
 Pixmap do_png(char *data, long len, long *wp, long *hp)
 {
-    png_struct		p_str;
-    png_info		p_info;
+    png_structp		png_ptr;
+    png_infop 		info_ptr;
     Pixmap		pixmap;
     FILE *volatile	vol_fp  = NULL;
     void *volatile	vol_pic = NULL;
@@ -92,13 +98,21 @@
 
     init_png_cmap();
 
-    if (!(vol_fp = dump_for_png(data, len))) {
-	ArtTextAddLine(main_widgets.text, "[knews: temp file error.]",
-		       ascii_font->body_font, global.alert_pixel);
-	return None;
+    if (!(vol_fp = dump_for_png(data, len)))
+	return rep_fail("[knews: temp file error.]");
+
+    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
+	NULL, NULL, NULL);
+    if (!png_ptr)
+	return rep_fail("[knews: can't allocate PNG structure.]");
+    info_ptr = png_create_info_struct(png_ptr);
+    if (!info_ptr) {
+	png_destroy_read_struct(&png_ptr,
+		(png_infopp)NULL, (png_infopp)NULL);
+	return rep_fail("[knews: can't PNG info structure.]");
     }
 
-    if (setjmp(p_str.jmpbuf))
+    if (setjmp(png_jmpbuf(png_ptr)))
 	ArtTextAddLine(main_widgets.text, "[knews: png error.]",
 		       ascii_font->body_font, global.alert_pixel);
     else {
@@ -108,58 +122,55 @@
 	unsigned int	per_line = 0;
 	unsigned int	i, j, pass;
 
-	png_read_init(&p_str);
-	png_info_init(&p_info);
-
-	png_init_io(&p_str, vol_fp);
-	png_read_info(&p_str, &p_info);
+	png_init_io(png_ptr, vol_fp);
+	png_read_info(png_ptr, info_ptr);
 
-	vol_w = w = p_info.width;
-	vol_h = h = p_info.height;
+	vol_w = w = info_ptr->width;
+	vol_h = h = info_ptr->height;
 
-	if (p_info.bit_depth == 16)
-	    png_set_strip_16(&p_str);
-	else if (p_info.bit_depth < 8)
-	    png_set_packing(&p_str);
+	if (info_ptr->bit_depth == 16)
+	    png_set_strip_16(png_ptr);
+	else if (info_ptr->bit_depth < 8)
+	    png_set_packing(png_ptr);
 
-	if (p_info.valid & PNG_INFO_bKGD)
-	    png_set_background(&p_str, &p_info.background,
+	if (info_ptr->valid & PNG_INFO_bKGD)
+	    png_set_background(png_ptr, &info_ptr->background,
 			       PNG_BACKGROUND_GAMMA_FILE, True, 1.0);
 	else {
 	    static png_color_16	bg = {0, };
-	    png_set_background(&p_str, &bg,
+	    png_set_background(png_ptr, &bg,
 			       PNG_BACKGROUND_GAMMA_SCREEN, False, 1.0);
 	}
 
 	per_line = w;
 
-	if (!(p_info.color_type & PNG_COLOR_MASK_COLOR)) { /* grey image */
+	if (!(info_ptr->color_type & PNG_COLOR_MASK_COLOR)) { /* grey image */
 	    grey = True;
-	    png_set_expand(&p_str);
+	    png_set_expand(png_ptr);
 	} else if (!p_cmap) { /* true color visual */
-	    if (p_info.color_type == PNG_COLOR_TYPE_PALETTE)
-		png_set_expand(&p_str);
+	    if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE)
+		png_set_expand(png_ptr);
 	    per_line *= 3;
-	} else if (p_info.color_type & PNG_COLOR_MASK_PALETTE) {
+	} else if (info_ptr->color_type & PNG_COLOR_MASK_PALETTE) {
 	    CMAP_ENTRY	*pal;
 	    int		i, pn;
 
-	    pn  = p_info.num_palette;
+	    pn  = info_ptr->num_palette;
 	    pal = (CMAP_ENTRY *)XtMalloc(pn * sizeof *pal);
 	    for (i = 0 ; i < pn ; i++) {
-		pal[i].r = p_info.palette[i].red;
-		pal[i].g = p_info.palette[i].green;
-		pal[i].b = p_info.palette[i].blue;
+		pal[i].r = info_ptr->palette[i].red;
+		pal[i].g = info_ptr->palette[i].green;
+		pal[i].b = info_ptr->palette[i].blue;
 	    }
 	    vol_pal = pal;
 	    vol_pn  = pn;
 	} else {
-	    png_set_dither(&p_str, p_cmap, cmap_size,
+	    png_set_dither(png_ptr, p_cmap, cmap_size,
 			   cmap_size, NULL, True);
 	}
 
-	pass = png_set_interlace_handling(&p_str);
-	png_start_read_image(&p_str);
+	pass = png_set_interlace_handling(png_ptr);
+	png_start_read_image(png_ptr);
 
 	vol_pic = pic = (unsigned char *)XtMalloc(h * per_line);
 
@@ -167,14 +178,14 @@
 	for (i = 0 ; i < pass ; i++) {
 	    row = pic;
 	    for (j = 0 ; j < h ; j++) {
-		png_read_row(&p_str, NULL, row);
+		png_read_row(png_ptr, NULL, row);
 		if (!did)
 		    vol_did = did = True;
 		row += per_line;
 	    }
 	}
 
-	png_read_end(&p_str, NULL);
+	png_read_end(png_ptr, NULL);
     }
 
     if (!vol_did)
@@ -204,7 +215,7 @@
 	}
     }
 
-    png_read_destroy(&p_str, &p_info, NULL);
+    png_read_destroy(png_ptr, info_ptr, NULL);
     fclose((FILE *)vol_fp);
     XtFree((char *)vol_pic);
     XtFree((char *)vol_pal);
