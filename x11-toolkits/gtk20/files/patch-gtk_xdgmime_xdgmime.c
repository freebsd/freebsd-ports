--- gtk/xdgmime/xdgmime.c.orig	Wed Jun 23 20:19:43 2004
+++ gtk/xdgmime/xdgmime.c	Wed Jun 23 20:19:56 2004
@@ -98,7 +98,7 @@
 
       xdg_data_dirs = getenv ("XDG_DATA_DIRS");
       if (xdg_data_dirs == NULL)
-	xdg_data_dirs = "/usr/local/share/:/usr/share/";
+	xdg_data_dirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 
       ptr = xdg_data_dirs;
 
