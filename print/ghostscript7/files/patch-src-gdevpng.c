--- src/gdevpng.c.orig	2003-05-15 12:05:29.000000000 +0200
+++ src/gdevpng.c	2012-04-27 20:17:30.000000000 +0200
@@ -258,7 +258,7 @@
 	goto done;
     }
     /* set error handling */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* If we get here, we had a problem reading the file */
 	code = gs_note_error(gs_error_VMerror);
 	goto done;
