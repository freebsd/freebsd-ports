--- ./src/panelModules/panelVibration.c.orig	2009-10-20 15:55:16.000000000 +0200
+++ ./src/panelModules/panelVibration.c	2010-11-25 18:38:52.000000000 +0100
@@ -55,7 +55,7 @@
 /* static void onFreqChecked(GtkToggleButton *toggle, gpointer data); */
 
 /* Setup the selection handler */
-static GtkTreeSelection *select;
+static GtkTreeSelection *selection;
 
 /* The string common to all paths in currentBrowseredDirectory. */
 static gchar *commonBrowseredDirectory;
@@ -161,8 +161,8 @@
   treeView = gtk_tree_view_new();
   CellRender = gtk_cell_renderer_text_new();
   /* when clicking in the treeView */
-  select = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeView));
-  gtk_tree_selection_set_mode (select, GTK_SELECTION_SINGLE);
+  selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeView));
+  gtk_tree_selection_set_mode (selection, GTK_SELECTION_SINGLE);
 
   /* make and add the first column to the view */
   column =  gtk_tree_view_column_new_with_attributes(_("id"), CellRender,
@@ -262,7 +262,7 @@
 		   G_CALLBACK(onDataReady), (gpointer)0);
   g_signal_connect(VISU_INSTANCE, "dataNew",
 		   G_CALLBACK(onDataNew), (gpointer)0);
-  g_signal_connect (G_OBJECT (select), "changed",
+  g_signal_connect (G_OBJECT (selection), "changed",
                    G_CALLBACK (onViewClikcked),
                    NULL);
  
@@ -374,7 +374,7 @@
   DBG_fprintf(stderr, "panelVibration: reseting all nodes position \n");
   if (play)
     onStopClicked(GTK_BUTTON(buttonStop), (gpointer)0);
-  gtk_tree_selection_unselect_all(select);
+  gtk_tree_selection_unselect_all(selection);
 }
 
 static void fillTreeView(VisuData *data) {
@@ -436,7 +436,7 @@
 
   model = GTK_TREE_MODEL(pListStore);
 
-  if (!gtk_tree_selection_get_selected(select, &model, &iter))
+  if (!gtk_tree_selection_get_selected(selection, &model, &iter))
     {
       gtk_widget_set_sensitive(buttonPlay, FALSE);
       gtk_widget_set_sensitive(buttonReset, FALSE);
