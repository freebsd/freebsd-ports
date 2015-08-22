--- src/gdevpng.c.orig	2003-05-15 19:05:29.000000000 +0900
+++ src/gdevpng.c	2015-02-19 01:59:24.000000000 +0900
@@ -41,12 +41,6 @@
 #include "gdevpccm.h"
 #include "gscdefs.h"
 
-#define PNG_INTERNAL
-/*
- * libpng versions 1.0.3 and later allow disabling access to the stdxxx
- * files while retaining support for FILE * I/O.
- */
-#define PNG_NO_CONSOLE_IO
 /*
  * Earlier libpng versions require disabling FILE * I/O altogether.
  * This produces a compiler warning about no prototype for png_init_io.
@@ -258,7 +252,7 @@
 	goto done;
     }
     /* set error handling */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* If we get here, we had a problem reading the file */
 	code = gs_note_error(gs_error_VMerror);
 	goto done;
@@ -268,19 +262,12 @@
     png_init_io(png_ptr, file);
 
     /* set the file information here */
-    info_ptr->width = pdev->width;
-    info_ptr->height = pdev->height;
-    /* resolution is in pixels per meter vs. dpi */
-    info_ptr->x_pixels_per_unit =
-	(png_uint_32) (pdev->HWResolution[0] * (100.0 / 2.54));
-    info_ptr->y_pixels_per_unit =
-	(png_uint_32) (pdev->HWResolution[1] * (100.0 / 2.54));
-    info_ptr->phys_unit_type = PNG_RESOLUTION_METER;
-    info_ptr->valid |= PNG_INFO_pHYs;
     switch (depth) {
 	case 32:
-	    info_ptr->bit_depth = 8;
-	    info_ptr->color_type = PNG_COLOR_TYPE_RGB_ALPHA;
+	    png_set_IHDR(png_ptr, info_ptr, pdev->width, pdev->height,
+		8, PNG_COLOR_TYPE_RGB_ALPHA,
+		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
+		PNG_FILTER_TYPE_DEFAULT);
 	    png_set_invert_alpha(png_ptr);
 	    {   gx_device_pngalpha *ppdev = (gx_device_pngalpha *)pdev;
 		png_color_16 background;
@@ -292,51 +279,68 @@
 		png_set_bKGD(png_ptr, info_ptr, &background);
 	    }
 	    break;
+	case 48:
+	    png_set_IHDR(png_ptr, info_ptr, pdev->width, pdev->height,
+		16, PNG_COLOR_TYPE_RGB,
+		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
+		PNG_FILTER_TYPE_DEFAULT);
+#if defined(ARCH_IS_BIG_ENDIAN) && (!ARCH_IS_BIG_ENDIAN) 
+	    png_set_swap(png_ptr);
+#endif
+	    break;
 	case 24:
-	    info_ptr->bit_depth = 8;
-	    info_ptr->color_type = PNG_COLOR_TYPE_RGB;
+	    png_set_IHDR(png_ptr, info_ptr, pdev->width, pdev->height,
+		8, PNG_COLOR_TYPE_RGB,
+		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
+		PNG_FILTER_TYPE_DEFAULT);
 	    break;
 	case 8:
-	    info_ptr->bit_depth = 8;
-	    if (gx_device_has_color(pdev))
-		info_ptr->color_type = PNG_COLOR_TYPE_PALETTE;
-	    else
-		info_ptr->color_type = PNG_COLOR_TYPE_GRAY;
+	    png_set_IHDR(png_ptr, info_ptr, pdev->width, pdev->height,
+		8, gx_device_has_color(pdev) ?
+		    PNG_COLOR_TYPE_PALETTE : PNG_COLOR_TYPE_GRAY,
+		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
+		PNG_FILTER_TYPE_DEFAULT);
 	    break;
 	case 4:
-	    info_ptr->bit_depth = 4;
-	    info_ptr->color_type = PNG_COLOR_TYPE_PALETTE;
+	    png_set_IHDR(png_ptr, info_ptr, pdev->width, pdev->height,
+		4, PNG_COLOR_TYPE_PALETTE,
+		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
+		PNG_FILTER_TYPE_DEFAULT);
 	    break;
 	case 1:
-	    info_ptr->bit_depth = 1;
-	    info_ptr->color_type = PNG_COLOR_TYPE_GRAY;
+	    png_set_IHDR(png_ptr, info_ptr, pdev->width, pdev->height,
+		1, PNG_COLOR_TYPE_PALETTE,
+		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
+		PNG_FILTER_TYPE_DEFAULT);
 	    /* invert monocrome pixels */
 	    png_set_invert_mono(png_ptr);
 	    break;
     }
 
+    /* resolution is in pixels per meter vs. dpi */
+    png_set_pHYs(png_ptr, info_ptr, 
+      (png_uint_32) (pdev->HWResolution[0] * (100.0 / 2.54)),
+      (png_uint_32) (pdev->HWResolution[1] * (100.0 / 2.54)),
+      PNG_RESOLUTION_METER);
+
     /* set the palette if there is one */
-    if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
+    if (png_get_color_type(png_ptr, info_ptr)  == PNG_COLOR_TYPE_PALETTE) {
 	int i;
 	int num_colors = 1 << depth;
 	gx_color_value rgb[3];
+	png_color palette[256];
+
+	if (num_colors > 256)
+	    num_colors = 256;
 
-	info_ptr->palette =
-	    (void *)gs_alloc_bytes(mem, 256 * sizeof(png_color),
-				   "png palette");
-	if (info_ptr->palette == 0) {
-	    code = gs_note_error(gs_error_VMerror);
-	    goto done;
-	}
-	info_ptr->num_palette = num_colors;
-	info_ptr->valid |= PNG_INFO_PLTE;
 	for (i = 0; i < num_colors; i++) {
 	    (*dev_proc(pdev, map_color_rgb)) ((gx_device *) pdev,
 					      (gx_color_index) i, rgb);
-	    info_ptr->palette[i].red = gx_color_value_to_byte(rgb[0]);
-	    info_ptr->palette[i].green = gx_color_value_to_byte(rgb[1]);
-	    info_ptr->palette[i].blue = gx_color_value_to_byte(rgb[2]);
+	    palette[i].red = gx_color_value_to_byte(rgb[0]);
+	    palette[i].green = gx_color_value_to_byte(rgb[1]);
+	    palette[i].blue = gx_color_value_to_byte(rgb[2]);
 	}
+	png_set_PLTE(png_ptr, info_ptr, palette, num_colors);
     }
     /* add comment */
     strncpy(software_key, "Software", sizeof(software_key));
@@ -346,15 +350,16 @@
     text_png.key = software_key;
     text_png.text = software_text;
     text_png.text_length = strlen(software_text);
-    info_ptr->text = &text_png;
-    info_ptr->num_text = 1;
+    png_set_text(png_ptr, info_ptr, &text_png, 1);
 
     /* write the file information */
     png_write_info(png_ptr, info_ptr);
 
     /* don't write the comments twice */
+#if 0
     info_ptr->num_text = 0;
     info_ptr->text = NULL;
+#endif
 
     /* Write the contents of the image. */
     for (y = 0; y < height; y++) {
@@ -365,8 +370,10 @@
     /* write the rest of the file */
     png_write_end(png_ptr, info_ptr);
 
+#if 0
     /* if you alloced the palette, free it here */
     gs_free_object(mem, info_ptr->palette, "png palette");
+#endif
 
   done:
     /* free the structures */
@@ -376,6 +383,7 @@
     return code;
 }
 
+#if 0
 /*
  * Patch around a static reference to a never-used procedure.
  * This could be avoided if we were willing to edit pngconf.h to
@@ -393,6 +401,7 @@
 {
 }
 #endif
+#endif
 
 private int
 pngalpha_open(gx_device * pdev)
