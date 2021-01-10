--- dialogs/appearance-settings/main.c.orig	2020-12-16 10:44:46 UTC
+++ dialogs/appearance-settings/main.c
@@ -994,7 +994,7 @@ appearance_settings_install_theme_cb (GtkButton *widge
         gchar **uris;
         GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
 
-        uris = g_new0 (gchar *, 1);
+        uris = g_new0 (gchar *, 2);
         filename = gtk_file_chooser_get_filename (chooser);
         uris[0] = g_filename_to_uri (filename, NULL, NULL);
         install_theme (window, uris, builder);
