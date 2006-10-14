--- src/e-contact-entry.c.orig	Sat Sep 30 19:54:33 2006
+++ src/e-contact-entry.c	Sat Sep 30 19:56:09 2006
@@ -261,8 +261,8 @@
 
       loader = gdk_pixbuf_loader_new ();
 
-      if (gdk_pixbuf_loader_write (loader, (guchar *)photo->data,
-			      photo->length, NULL))
+      if (gdk_pixbuf_loader_write (loader, (guchar *)photo->data.inlined.data,
+			      photo->data.inlined.length, NULL))
         pixbuf = gdk_pixbuf_loader_get_pixbuf (loader);
 
       if (pixbuf) {
