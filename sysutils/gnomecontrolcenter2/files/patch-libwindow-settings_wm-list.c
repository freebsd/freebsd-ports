--- libwindow-settings/wm-list.c.orig	Tue Oct  8 17:43:12 2002
+++ libwindow-settings/wm-list.c	Tue Oct  8 17:43:25 2002
@@ -251,7 +251,7 @@
         gchar *name;
 	GConfClient *client;
 	
-        tempdir = gnome_unconditional_datadir_file ("gnome/wm-properties/");
+        tempdir = gnome_unconditional_datadir_file ("wm-properties/");
         wm_list_read_dir (tempdir, FALSE);
         g_free (tempdir);
         
