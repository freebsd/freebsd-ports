--- src/gdevxini.c.orig	Tue Jun  5 15:38:57 2001
+++ src/gdevxini.c	Wed Jun 20 04:17:15 2001
@@ -655,8 +655,10 @@
     }
     x_set_buffer(xdev);
     /* Clear the destination pixmap to avoid initializing with garbage. */
-    xdev->dest = (xdev->bpixmap != (Pixmap) 0 ?
+    if (xdev->dest == (Pixmap) 0) {
+    	xdev->dest = (xdev->bpixmap != (Pixmap) 0 ?
 		  xdev->bpixmap : (Pixmap) xdev->win);
+    }
     if (xdev->dest != (Pixmap) 0) {
 	XSetForeground(xdev->dpy, xdev->gc, xdev->background);
 	XFillRectangle(xdev->dpy, xdev->dest, xdev->gc,
