--- gtk/gtkicontheme.c.orig	Thu Jan 29 16:53:42 2004
+++ gtk/gtkicontheme.c	Thu Jan 29 16:54:56 2004
@@ -526,7 +526,7 @@
 
   priv->custom_theme = FALSE;
   priv->current_theme = g_strdup (DEFAULT_THEME_NAME);
-  priv->search_path = g_new (char *, 5);
+  priv->search_path = g_new (char *, 7);
   
 
   priv->search_path[0] = g_build_filename (g_get_home_dir (),
@@ -534,9 +534,11 @@
 					   NULL);
   priv->search_path[1] = g_build_filename (GTK_DATADIR, "pixmaps", NULL);
   priv->search_path[2] = g_build_filename (GTK_DATADIR, "icons", NULL);
-  priv->search_path[3] = g_strdup ("/usr/share/icons");
-  priv->search_path[4] = g_strdup ("/usr/share/pixmaps");
-  priv->search_path_len = 5;
+  priv->search_path[3] = g_build_filename (GTK_DATADIR, "gnome", "pixmaps", NULL);
+  priv->search_path[4] = g_build_filename (GTK_DATADIR, "gnome", "icons", NULL);
+  priv->search_path[5] = g_strdup ("/usr/share/icons");
+  priv->search_path[6] = g_strdup ("/usr/share/pixmaps");
+  priv->search_path_len = 7;
 
   priv->themes_valid = FALSE;
   priv->themes = NULL;
