--- src/playlist.h.orig	2014-04-24 03:38:08 UTC
+++ src/playlist.h
@@ -29,8 +29,8 @@
 #include <glib.h>
 #include <glib/gstdio.h>
 
-GtkWidget *plclose;
-gint window_width, window_height;
+extern GtkWidget *plclose;
+extern gint window_width, window_height;
 
 void update_gui();
 void menuitem_view_playlist_callback(GtkMenuItem * menuitem, void *data);
