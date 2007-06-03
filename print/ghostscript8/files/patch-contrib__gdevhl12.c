--- contrib/gdevhl12.c.orig	Thu Apr 26 01:27:24 2007
+++ contrib/gdevhl12.c	Tue May 15 16:49:03 2007
@@ -474,7 +474,7 @@
 	    continue;
 #if 1
 	/* XXX - please report if you ever see this, then change to #if 0 */
-	fprintf(stderr,
+	dprintf1(
 		"hl1250: compression failed (y=%u), doing 1200x300 dpi\n",
 		band + y);
 #endif
