--- src/gconf-editor-window.c.orig	Mon Apr 24 03:19:49 2006
+++ src/gconf-editor-window.c	Mon Apr 24 03:20:00 2006
@@ -950,7 +950,7 @@ gconf_editor_gconf_value_changed (GConfC
 		gconf_add_recent_key (window, key);
 	}
 
-	g_free (value);
+	gconf_value_free (value);
 	g_free (key);
 	gtk_tree_path_free (path);
 }
