--- gai/gai-gnome.c.orig	Mon May 10 09:16:17 2004
+++ gai/gai-gnome.c	Mon May 10 09:16:26 2004
@@ -345,8 +345,8 @@
 static int
 gai_gnome_expose(GtkWidget *widget, GdkEventExpose *event, gpointer d)
 {
-    GAI_ENTER;
     static gboolean expose_lock = FALSE;
+    GAI_ENTER;
     if(expose_lock){
 	GAI_NOTE("Expose lock");
 	return FALSE;
