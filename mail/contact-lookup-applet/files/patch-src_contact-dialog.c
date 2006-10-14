--- src/contact-dialog.c.orig	Sat Sep 30 19:56:51 2006
+++ src/contact-dialog.c	Sat Sep 30 19:57:14 2006
@@ -260,7 +260,7 @@
 
       loader = gdk_pixbuf_loader_new ();
 
-      if (!gdk_pixbuf_loader_write (loader, photo->data, photo->length, NULL)) {
+      if (!gdk_pixbuf_loader_write (loader, photo->data.inlined.data, photo->data.inlined.length, NULL)) {
         gtk_widget_hide (photo_frame);
       } else if( (pixbuf = gdk_pixbuf_loader_get_pixbuf (loader)) != NULL ) {
         GdkPixbuf *tmp;
