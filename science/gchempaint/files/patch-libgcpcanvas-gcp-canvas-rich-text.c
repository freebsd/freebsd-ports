--- libgcpcanvas/gcp-canvas-rich-text.c.orig	Mon Nov 29 08:46:09 2004
+++ libgcpcanvas/gcp-canvas-rich-text.c	Tue Nov 30 00:19:42 2004
@@ -1699,9 +1699,10 @@
 static gboolean
 request_update(gpointer data)
 {
+	GnomeCanvasRichTextExt *text;
 	if (!GNOME_IS_CANVAS_RICH_TEXT_EXT (data))
 		return;
-	GnomeCanvasRichTextExt *text = GNOME_CANVAS_RICH_TEXT_EXT(data);
+	text = GNOME_CANVAS_RICH_TEXT_EXT(data);
 
 	gnome_canvas_item_request_update(GNOME_CANVAS_ITEM(text));
 
@@ -2420,10 +2421,13 @@
 gnome_canvas_rich_text_ext_ensure_rendered (GnomeCanvasRichTextExt *text)
 {
 	double x1, y1, x2, y2;
-	get_bounds (text, &x1, &y1, &x2, &y2);
-	int w = (int) (ceil (x2) - floor (x1)) + 1, h = (int) (ceil (y2) - floor (y1)) + 1;
-	GdkPixbuf *pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, w, h);
+	int w, h;
+	GdkPixbuf *pixbuf;
 	GnomeCanvasBuf buf;
+
+	get_bounds (text, &x1, &y1, &x2, &y2);
+	w = (int) (ceil (x2) - floor (x1)) + 1, h = (int) (ceil (y2) - floor (y1)) + 1;
+	pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, w, h);
 	buf.buf = gdk_pixbuf_get_pixels (pixbuf);
 	buf.rect.x0 = (int) floor (x1);
 	buf.rect.x1 = (int) ceil (x2);
