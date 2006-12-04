--- audacious/ui_playlist.c.orig	Fri Dec  1 14:28:04 2006
+++ audacious/ui_playlist.c	Fri Dec  1 14:28:24 2006
@@ -300,9 +300,10 @@
 gint
 playlistwin_get_height_unshaded(void)
 {
+    gint height;
     cfg.playlist_height /= PLAYLISTWIN_HEIGHT_SNAP;
     cfg.playlist_height *= PLAYLISTWIN_HEIGHT_SNAP;
-    gint height = cfg.playlist_height;
+    height = cfg.playlist_height;
     return height;
 }
 
