--- libgcpcanvas/gcp-canvas-text.c.orig	Mon Nov 29 08:46:09 2004
+++ libgcpcanvas/gcp-canvas-text.c	Tue Nov 30 00:37:59 2004
@@ -228,10 +228,13 @@
 gnome_canvas_text_ext_ensure_rendered (GnomeCanvasTextExt *text)
 {
 	double x1, y1, x2, y2;
-	gnome_canvas_item_get_bounds (GNOME_CANVAS_ITEM (text), &x1, &y1, &x2, &y2);
-	int w = (int) (ceil (x2) - floor (x1)) + 1, h = (int) (ceil (y2) - floor (y1)) + 1;
-	GdkPixbuf *pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, w, h);
+	int w, h;
 	GnomeCanvasBuf buf;
+	GdkPixbuf *pixbuf;
+
+	gnome_canvas_item_get_bounds (GNOME_CANVAS_ITEM (text), &x1, &y1, &x2, &y2);
+	w = (int) (ceil (x2) - floor (x1)) + 1, h = (int) (ceil (y2) - floor (y1)) + 1;
+	pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, w, h);
 	buf.buf = gdk_pixbuf_get_pixels (pixbuf);
 	buf.rect.x0 = (int) floor (x1);
 	buf.rect.x1 = (int) ceil (x2);
