--- lib/rotate.c.orig	2012-11-30 14:57:39.000000000 +0100
+++ lib/rotate.c	2012-11-30 14:58:50.000000000 +0100
@@ -31,6 +31,7 @@
 /*
  * Set the rotation of glyph g to r.
  */
+void
 SetRotation(g, r)
 	register struct glyph *g;
 	int r;
