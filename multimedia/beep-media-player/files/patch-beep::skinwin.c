--- beep/skinwin.c.orig	Fri Nov 14 05:30:38 2003
+++ beep/skinwin.c	Fri Nov 14 05:32:30 2003
@@ -190,6 +190,10 @@
 	GtkTreeView * treeview = GTK_TREE_VIEW(data);
 	GtkListStore * model;
 	GtkTreeSelection * l_selection;
+	guint max;
+	guint loop;
+	char * comp;
+
 	
 	/* FIXME:
 	 *  This is all alittle of bad mojo here, the gtk-doc says about the "changed" signal for GtkTreeSelection:
@@ -202,10 +206,6 @@
 	if (!gtk_tree_selection_get_selected(GTK_TREE_SELECTION(l_selection),&model,&iter)) return;
 	gtk_tree_model_get (GTK_TREE_MODEL(model), &iter, 1, &name, -1);
 
-	guint max;
-	guint loop;
-	char * comp;
-	
 	max = g_list_length(skinlist);
 
 	for (loop = 0; loop < max; loop++) {
@@ -423,6 +423,8 @@
 	GtkListStore *store;
 	GtkTreeModel *model;
 
+	GtkWidget *selection;
+
 	skinwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_widget_set_usize(skinwin,500,380);
 	gtk_window_set_position(GTK_WINDOW(skinwin),GTK_WIN_POS_CENTER);
@@ -493,7 +495,7 @@
         gtk_tree_view_column_set_spacing(column, 16);
 	gtk_tree_view_column_set_attributes (column, renderer, "text", 1, NULL);
 
-	GtkWidget *selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview));
+	selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview));
 	g_signal_connect(G_OBJECT(selection), "changed", G_CALLBACK(change_skin_event), treeview);
 	g_signal_connect(G_OBJECT(skinwin), "key_press_event", G_CALLBACK(skinwin_keypress_cb), NULL);
 	g_signal_connect(G_OBJECT(skinwin), "show",G_CALLBACK(update_skins),treeview);
