--- src/gnome2/mod_mgr.c.orig	Sun Mar 28 04:39:23 2004
+++ src/gnome2/mod_mgr.c	Sat Aug 21 15:56:12 2004
@@ -1910,8 +1910,7 @@
 
 	GtkTreeModel *model;
 	GError *error = NULL;
-	GtkTooltips *tooltips;
-	tooltips = gtk_tooltips_new();
+	GtkTooltips *tooltips = gtk_tooltips_new();
 	GString *str = g_string_new(NULL);
 	GtkCellRenderer *renderer;
 	GtkTreeViewColumn *column;
