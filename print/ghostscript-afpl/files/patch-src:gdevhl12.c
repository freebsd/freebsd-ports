--- src/gdevhl12.c.orig	Wed Mar 28 14:10:35 2007
+++ src/gdevhl12.c	Wed Mar 28 14:13:21 2007
@@ -472,7 +472,7 @@
     for (y = ytop; y < ybottom; y++) {
 	if (hl1250_compress_line(s, y))
 	    continue;
-#if 1
+#if 0
 	/* XXX - please report if you ever see this, then change to #if 0 */
 	fprintf(stderr,
 		"hl1250: compression failed (y=%u), doing 1200x300 dpi\n",
