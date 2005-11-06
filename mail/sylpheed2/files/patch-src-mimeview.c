--- src/mimeview.c.orig	Sun Nov  6 01:01:21 2005
+++ src/mimeview.c	Sun Nov  6 01:01:36 2005
@@ -204,7 +204,7 @@
 	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
 
 	gtk_tree_view_enable_model_drag_source
-		(GTK_TREE_VIEW(treeview), 0, mimeview_mime_types, 1,
+		(GTK_TREE_VIEW(treeview), GDK_BUTTON1_MASK, mimeview_mime_types, 1,
 		 GDK_ACTION_COPY);
 
 	g_signal_connect(G_OBJECT(selection), "changed",
