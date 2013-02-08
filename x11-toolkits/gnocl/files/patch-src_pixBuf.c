--- src/pixBuf.c.orig	2013-01-31 10:52:21.000000000 +0100
+++ src/pixBuf.c	2013-02-01 14:22:55.000000000 +0100
@@ -90,6 +90,9 @@
 /* Key for automated pixbuf updating and destruction */
 static const cairo_user_data_key_t pixbuf_key;
 
+void gdk_pixbuf_get_pixel ( GdkPixbuf * pixbuf, guint x, guint y , guchar * r, guchar * g, guchar * b, guchar * a );
+void gdk_pixbuf_set_pixel ( GdkPixbuf * pixbuf, guint32 pixel, guint x, guint y );
+
 
 /**
 \brief	This function will initialize new cairo context with contents of
