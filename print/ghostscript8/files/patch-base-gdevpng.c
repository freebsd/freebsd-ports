--- base/gdevpng.c.orig	2008-07-17 04:34:01.000000000 +0200
+++ base/gdevpng.c	2012-04-27 20:19:52.000000000 +0200
@@ -280,7 +280,7 @@
 	goto done;
     }
     /* set error handling */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* If we get here, we had a problem reading the file */
 	code = gs_note_error(gs_error_VMerror);
 	goto done;
