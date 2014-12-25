$NetBSD: patch-bd,v 1.3 2011/01/15 19:16:00 tron Exp $

Fix build with png-1.5.

--- src/png.c.orig	1998-11-21 14:55:13.000000000 +0000
+++ src/png.c	2011-01-15 19:09:09.000000000 +0000
@@ -78,8 +78,8 @@
 
 Pixmap do_png(char *data, long len, long *wp, long *hp)
 {
-    png_struct		p_str;
-    png_info		p_info;
+    png_struct		*p_str = NULL;
+    png_info		*p_info = NULL;
     Pixmap		pixmap;
     FILE *volatile	vol_fp  = NULL;
     void *volatile	vol_pic = NULL;
@@ -98,7 +98,11 @@
 	return None;
     }
 
-    if (setjmp(p_str.jmpbuf))
+    if ((p_str = (png_struct *) png_create_read_struct(PNG_LIBPNG_VER_STRING,
+		    NULL, NULL, NULL)))
+	p_info = (png_info *) png_create_info_struct(p_str);
+
+    if (p_str && p_info && setjmp(png_jmpbuf(p_str)))
 	ArtTextAddLine(main_widgets.text, "[knews: png error.]",
 		       ascii_font->body_font, global.alert_pixel);
     else {
@@ -107,59 +111,63 @@
 	int		did;
 	unsigned int	per_line = 0;
 	unsigned int	i, j, pass;
+	png_color_16p	background;
+        png_byte        color_type;
+	png_colorp	palette;
+	int		num_palette;
+
+	png_init_io(p_str, vol_fp);
+	png_read_info(p_str, p_info);
+
+	vol_w = w = png_get_image_width(p_str, p_info);
+	vol_h = h = png_get_image_height(p_str, p_info);
+
+	if (png_get_bit_depth(p_str, p_info) == 16)
+	    png_set_strip_16(p_str);
+	else if (png_get_bit_depth(p_str, p_info) < 8)
+	    png_set_packing(p_str);
 
-	png_read_init(&p_str);
-	png_info_init(&p_info);
-
-	png_init_io(&p_str, vol_fp);
-	png_read_info(&p_str, &p_info);
-
-	vol_w = w = p_info.width;
-	vol_h = h = p_info.height;
-
-	if (p_info.bit_depth == 16)
-	    png_set_strip_16(&p_str);
-	else if (p_info.bit_depth < 8)
-	    png_set_packing(&p_str);
-
-	if (p_info.valid & PNG_INFO_bKGD)
-	    png_set_background(&p_str, &p_info.background,
+	if (png_get_bKGD(p_str, p_info, &background) & PNG_INFO_bKGD)
+	    png_set_background(p_str, background,
 			       PNG_BACKGROUND_GAMMA_FILE, True, 1.0);
 	else {
 	    static png_color_16	bg = {0, };
-	    png_set_background(&p_str, &bg,
+	    png_set_background(p_str, &bg,
 			       PNG_BACKGROUND_GAMMA_SCREEN, False, 1.0);
 	}
 
 	per_line = w;
 
-	if (!(p_info.color_type & PNG_COLOR_MASK_COLOR)) { /* grey image */
+        color_type = png_get_color_type(p_str, p_info);
+	if (!(color_type & PNG_COLOR_MASK_COLOR)) { /* grey image */
 	    grey = True;
-	    png_set_expand(&p_str);
+	    png_set_expand(p_str);
 	} else if (!p_cmap) { /* true color visual */
-	    if (p_info.color_type == PNG_COLOR_TYPE_PALETTE)
-		png_set_expand(&p_str);
+	    if (color_type == PNG_COLOR_TYPE_PALETTE)
+		png_set_expand(p_str);
 	    per_line *= 3;
-	} else if (p_info.color_type & PNG_COLOR_MASK_PALETTE) {
+	} else if (color_type & PNG_COLOR_MASK_PALETTE &&
+		   png_get_PLTE(p_str, p_info,
+				&palette, &num_palette) & PNG_INFO_PLTE) {
 	    CMAP_ENTRY	*pal;
 	    int		i, pn;
 
-	    pn  = p_info.num_palette;
+	    pn  = num_palette;
 	    pal = (CMAP_ENTRY *)XtMalloc(pn * sizeof *pal);
 	    for (i = 0 ; i < pn ; i++) {
-		pal[i].r = p_info.palette[i].red;
-		pal[i].g = p_info.palette[i].green;
-		pal[i].b = p_info.palette[i].blue;
+		pal[i].r = palette[i].red;
+		pal[i].g = palette[i].green;
+		pal[i].b = palette[i].blue;
 	    }
 	    vol_pal = pal;
 	    vol_pn  = pn;
 	} else {
-	    png_set_dither(&p_str, p_cmap, cmap_size,
-			   cmap_size, NULL, True);
+	    png_set_quantize(p_str, p_cmap, cmap_size,
+			     cmap_size, NULL, True);
 	}
 
-	pass = png_set_interlace_handling(&p_str);
-	png_start_read_image(&p_str);
+	pass = png_set_interlace_handling(p_str);
+	png_start_read_image(p_str);
 
 	vol_pic = pic = (unsigned char *)XtMalloc(h * per_line);
 
@@ -167,14 +175,14 @@
 	for (i = 0 ; i < pass ; i++) {
 	    row = pic;
 	    for (j = 0 ; j < h ; j++) {
-		png_read_row(&p_str, NULL, row);
+		png_read_row(p_str, NULL, row);
 		if (!did)
 		    vol_did = did = True;
 		row += per_line;
 	    }
 	}
 
-	png_read_end(&p_str, NULL);
+	png_read_end(p_str, NULL);
     }
 
     if (!vol_did)
@@ -204,7 +212,10 @@
 	}
     }
 
-    png_read_destroy(&p_str, &p_info, NULL);
+    if (p_info)
+	png_destroy_read_struct(&p_str, &p_info, NULL);
+    else
+	png_destroy_read_struct(&p_str, NULL, NULL);
     fclose((FILE *)vol_fp);
     XtFree((char *)vol_pic);
     XtFree((char *)vol_pal);
