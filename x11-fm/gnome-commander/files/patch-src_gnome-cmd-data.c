--- src/gnome-cmd-data.c.orig	Wed Jun  5 14:25:15 2002
+++ src/gnome-cmd-data.c	Mon Jun 17 17:36:33 2002
@@ -520,7 +520,7 @@
 	data->priv->mime_scale_quality = get_int (
 		"/gnome-commander/options/mime_scale_quality", 3);
 	data->priv->mime_icon_dir = get_string (
-		"/gnome-commander/options/mime_icon_dir", "/usr/share/pixmaps/nautilus/");
+		"/gnome-commander/options/mime_icon_dir", "%%X11BASE%%/share/gnome/pixmaps/nautilus/");
 	data->priv->cmdline_history_length = get_int (
 		"/gnome-commander/options/cmdline_history_length", 16);
 	
