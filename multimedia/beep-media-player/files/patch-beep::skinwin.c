--- beep/skinwin.c.orig	Sat Feb  7 18:16:37 2004
+++ beep/skinwin.c	Sat Feb  7 18:17:50 2004
@@ -216,11 +216,12 @@
     int i;
     char *str, *skinsdir;
     gchar **list;
+	GtkTreeView *treeview;
+	GtkTreeSelection *selection = NULL;
+	GtkListStore *store;
 
     gtk_widget_set_sensitive(scrolled_win, FALSE);
-    GtkTreeView *treeview = GTK_TREE_VIEW(data);
-    GtkTreeSelection *selection = NULL;
-    GtkListStore *store;
+    treeview = GTK_TREE_VIEW(data);
 
     selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
     store = GTK_LIST_STORE(gtk_tree_view_get_model(treeview));
