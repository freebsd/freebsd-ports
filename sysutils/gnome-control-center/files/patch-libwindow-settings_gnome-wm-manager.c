--- libwindow-settings/gnome-wm-manager.c.orig	Mon Nov 11 00:42:08 2002
+++ libwindow-settings/gnome-wm-manager.c	Mon Nov 11 00:43:26 2002
@@ -227,7 +227,7 @@
 
         done_scan = TRUE;
         
-        tempdir = gnome_unconditional_datadir_file ("gnome/wm-properties/");
+        tempdir = gnome_unconditional_datadir_file ("wm-properties/");
         scan_wm_directory (tempdir, FALSE);
         g_free (tempdir);
         
