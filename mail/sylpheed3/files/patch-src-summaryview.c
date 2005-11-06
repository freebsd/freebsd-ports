--- src/summaryview.c.orig	Sun Nov  6 00:59:52 2005
+++ src/summaryview.c	Sun Nov  6 01:00:05 2005
@@ -4323,7 +4323,7 @@
 
 	gtk_tree_view_enable_model_drag_source
 		(GTK_TREE_VIEW(treeview),
-		 0, summary_drag_types, N_DRAG_TYPES,
+		 GDK_BUTTON1_MASK, summary_drag_types, N_DRAG_TYPES,
 		 GDK_ACTION_MOVE | GDK_ACTION_COPY);
 
 	g_signal_connect_after(G_OBJECT(treeview), "drag-begin",
