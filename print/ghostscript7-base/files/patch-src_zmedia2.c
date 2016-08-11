--- src/zmedia2.c.orig	Fri Apr 27 02:57:41 2001
+++ src/zmedia2.c	Fri Nov  2 04:08:16 2001
@@ -429,11 +429,17 @@
 
 	rx = ry, ry = temp;
     }
-    /* Adjust the medium size if flexible. */ 
-    if (medium->p.x < MIN_MEDIA_SIZE && mx > rx)
-	mx = rx;
-    if (medium->p.y < MIN_MEDIA_SIZE && my > ry)
-	my = ry;
+    /* If 'medium' is flexible, adjust 'mx' and 'my' towards 'rx' and 'ry',
+       respectively. Note that 'mx' and 'my' have just acquired the largest
+       permissible value, medium->q. */
+    if (medium->p.x < mx)	/* non-empty width range */
+      if (rx < medium->p.x) mx = medium->p.x;	/* minimum */
+      else if (mx > rx) mx = rx;	/* fits */
+      /* else use medium->q.x, i.e., the maximum */
+    if (medium->p.y < my)	/* non-empty height range */
+      if (ry < medium->p.y) my = medium->p.y;	/* minimum */
+      else if (my > ry) my = ry;	/* fits */
+      /* else use medium->q.y, i.e., the maximum */
 
     /* Translate to align the centers. */ 
     gs_make_translation(mx / 2, my / 2, pmat);
