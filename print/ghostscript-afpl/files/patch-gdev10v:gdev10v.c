--- gdev10v/gdev10v.c.orig	Sat Dec 11 04:10:45 1993
+++ gdev10v/gdev10v.c	Fri Dec 17 19:15:49 2004
@@ -152,8 +152,8 @@
 	int bytes_per_column = bits_per_column / 8;
 	int x_skip_unit = bytes_per_column * (xres / 180);
 	int y_skip_unit = (yres / 180);
-	byte *in = (byte *)gs_malloc(8, line_size, "bj10v_print_page(in)");
-	byte *out = (byte *)gs_malloc(bits_per_column, line_size, "bj10v_print_page(out)");
+	byte *in = (byte *)gs_malloc(pdev->memory, 8, line_size, "bj10v_print_page(in)");
+	byte *out = (byte *)gs_malloc(pdev->memory, bits_per_column, line_size, "bj10v_print_page(out)");
 	int lnum = 0;
 	int y_skip = 0;
 	int code = 0;
@@ -275,7 +275,7 @@
 	/* Eject the page */
 xit:	prn_putc(pdev, 014);	/* form feed */
 	prn_flush(pdev);
-	gs_free((char *)out, bits_per_column, line_size, "bj10v_print_page(out)");
-	gs_free((char *)in, 8, line_size, "bj10v_print_page(in)");
+	gs_free(pdev->memory, (char *)out, bits_per_column, line_size, "bj10v_print_page(out)");
+	gs_free(pdev->memory, (char *)in, 8, line_size, "bj10v_print_page(in)");
 	return code;
 }
