--- libgcpcanvas/gcp-canvas-rich-text.c.orig	Thu Aug 28 08:12:13 2003
+++ libgcpcanvas/gcp-canvas-rich-text.c	Thu Aug 28 18:07:40 2003
@@ -2101,6 +2101,11 @@
 	double ax, ay;
 	double x1, y1, x2, y2;
 	ArtPoint ip, cp;
+	GdkPixbuf *pxb;
+	GdkPixmap* pb;
+	GdkGC* gc;
+	GdkPixbuf* pixbuf;
+	GdkColormap* map;
 
     gnome_canvas_buf_ensure_buf (buf);
 
@@ -2149,11 +2154,11 @@
 	if (y0 + h >= buf->rect.y1 + 1)
 		h = buf->rect.y1 - y0 + 1;
 	if (((int) w == 0) || ((int) h == 0)) return;
-	GdkPixbuf *pxb = gdk_pixbuf_new_from_data (buf->buf + y * buf->buf_rowstride + x * 3,
+	pxb = gdk_pixbuf_new_from_data (buf->buf + y * buf->buf_rowstride + x * 3,
 																GDK_COLORSPACE_RGB, FALSE, 8, (int) w, (int) h,
 																buf->buf_rowstride, NULL, NULL);
-	GdkPixmap* pb = gdk_pixmap_new (item->canvas->layout.bin_window, (int) w, (int) h, gtk_widget_get_visual ((GtkWidget*) item->canvas)->depth);
-	GdkGC* gc = gdk_gc_new (pb);
+	pb = gdk_pixmap_new (item->canvas->layout.bin_window, (int) w, (int) h, gtk_widget_get_visual ((GtkWidget*) item->canvas)->depth);
+	gc = gdk_gc_new (pb);
 	gdk_pixbuf_render_to_drawable (pxb, pb, gc, 0, 0, 0, 0, w, h, GDK_RGB_DITHER_NONE, 0, 0);
 	gtk_text_layout_set_screen_width(text->_priv->layout, x2 - x1);
         /* FIXME: should last arg be NULL? */
@@ -2166,8 +2171,8 @@
 		0, 0, x2 - x0, y2 - y0,
 		NULL);
 
-	GdkPixbuf* pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, (int) w, (int) h);
-	GdkColormap* map = gdk_colormap_new (gtk_widget_get_visual ((GtkWidget*) item->canvas), FALSE);
+	pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, (int) w, (int) h);
+	map = gdk_colormap_new (gtk_widget_get_visual ((GtkWidget*) item->canvas), FALSE);
 	gdk_pixbuf_get_from_drawable (pixbuf, pb, map, 0, 0, 0, 0, (int) w, (int) h);
 	data = gdk_pixbuf_get_pixels (pixbuf);
 	r = gdk_pixbuf_get_rowstride (pixbuf);
@@ -2220,18 +2225,20 @@
 
 PangoLayout* gnome_canvas_rich_text_ext_get_pango_layout (GnomeCanvasRichTextExt *text, gint line)
 {
-	g_return_val_if_fail (GNOME_IS_CANVAS_RICH_TEXT_EXT (text), NULL);
 	gint top = 0, bottom, firsty;
+	GSList* lines;
+	GtkTextLine* text_line;
+	g_return_val_if_fail (GNOME_IS_CANVAS_RICH_TEXT_EXT (text), NULL);
 	gtk_text_layout_get_size (text->_priv->layout, NULL, &bottom);
 	if (bottom <= top) return NULL;
-	GSList* lines = gtk_text_layout_get_lines (text->_priv->layout, top, bottom, &firsty);
+	lines = gtk_text_layout_get_lines (text->_priv->layout, top, bottom, &firsty);
 	firsty = 0;
 	while ((firsty < line) && lines)
 	{
 		lines = lines->next;
 		firsty++;
 	}
-	GtkTextLine* text_line = (lines)? lines->data: NULL;
+	text_line = (lines)? lines->data: NULL;
 	if (text_line)
 	{
 		GtkTextLineDisplay* display = gtk_text_layout_get_line_display(text->_priv->layout, text_line, TRUE);
