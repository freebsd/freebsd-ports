--- src/gtkgs.c.orig	Tue Oct 23 23:37:33 2001
+++ src/gtkgs.c	Sat Feb  2 19:14:29 2002
@@ -1273,7 +1273,7 @@
 		fname = ggv_quote_filename (filename);
 		filename_dsc = tempnam (g_get_tmp_dir(), "dsc");
 		filename_err = tempnam (g_get_tmp_dir(), "err");
-		cmd = g_strdup_printf (gs_scan_pdf_cmd, "\"", fname ,"\"", "\", filename_dsc");
+		cmd = g_strdup_printf (gs_scan_pdf_cmd, fname, filename_dsc);
 		g_free (fname);
 		/* this command (sometimes?) prints error messages to stdout! */
 		cmdline = g_strdup_printf ("%s >%s 2>&1", cmd, filename_err);
