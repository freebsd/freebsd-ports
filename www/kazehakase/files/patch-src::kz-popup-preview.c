--- src/kz-popup-preview.c.orig	Tue Dec 28 23:16:00 2004
+++ src/kz-popup-preview.c	Tue Dec 28 23:16:50 2004
@@ -529,13 +529,13 @@
 	}
 	else
 	{
+		GdkPixbuf *scaled_pixbuf, *orig_pixbuf;
 		gint width = DEFAULT_WIDTH;
 		gint height = DEFAULT_HEIGHT;
 
 		KZ_CONF_GET("Popup", "width",  width, INT);
 		KZ_CONF_GET("Popup", "height", height, INT);
 
-		GdkPixbuf *scaled_pixbuf, *orig_pixbuf;
 
 		orig_pixbuf = gdk_pixbuf_new_from_file(popup_file_name, NULL);
 		if (!orig_pixbuf) return NULL;
