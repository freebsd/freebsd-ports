--- bookmarks/bookmarks-add-dialog.c.orig	Fri Jan 23 01:53:29 2004
+++ bookmarks/bookmarks-add-dialog.c	Fri Jan 23 01:53:48 2004
@@ -397,11 +397,12 @@
 				    gint int1, gint int2)
 {
 	GbTreeView *treeview = gb_tree_view_new();
+	GtkWidget *widget;
 
 	g_signal_handlers_disconnect_matched(treeview, G_SIGNAL_MATCH_DATA,
 					     0, 0, NULL, NULL, treeview);
 
-	GtkWidget *widget = GTK_WIDGET(treeview);
+	widget = GTK_WIDGET(treeview);
 	gtk_widget_show(widget);
 	return widget;
 }
