--- capplets/mouse/gnome-mouse-properties.c.orig	Mon Sep  5 17:05:46 2005
+++ capplets/mouse/gnome-mouse-properties.c	Mon Sep  5 17:06:23 2005
@@ -658,7 +658,8 @@
 
 	gchar **iterator = NULL;
 	gchar **paths = NULL;
-
+	const gchar *xpaths;
+	
 	GConfClient* client = gconf_client_get_default();
 	GtkListStore* store = GTK_LIST_STORE(gtk_tree_model_sort_get_model(model));
 	gchar* current_theme = gconf_client_get_string(client, CURSOR_THEME_KEY, NULL);
@@ -666,7 +667,7 @@
 	g_object_unref(client);
 	client = NULL;
 
-	const gchar *xpaths = g_getenv ("XCURSOR_PATH");
+	xpaths = g_getenv ("XCURSOR_PATH");
 
 	if (xpaths != NULL) {
 		paths = g_strsplit (xpaths, ":", 0);
