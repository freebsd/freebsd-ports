--- src/callbacks.c.orig	Mon May 30 23:53:06 2005
+++ src/callbacks.c	Sat Nov 12 18:15:45 2005
@@ -416,6 +416,15 @@
 /* enlever des fichiers a graver */
 void gtk_data_removefiles(GtkWidget *Abtn, gpointer Adata)
 {
+  GtkTreeModel *Ltreedata;
+  GtkTreeSelection *Lselection;
+  GList *Lfiles;
+  GList *Lrefs;
+  GList *Lnode;
+  gint Ltype;
+  guint32 Lsizenbr = 0;
+  GtkTreeIter Liter;
+  gpointer Lproxy;
   Tgrave *Lg = (Tgrave *)Adata;
   GtkTreeView *Lliste = GTK_TREE_VIEW(sc_grave_get_data(Lg, "_current_list"));
   GtkProgressBar *Lcontenance;
@@ -428,15 +437,12 @@
 #if 0  
   GtkTreeIter *Literboot = sc_grave_get_data(Lg, "file_imageboot");
 #endif
-  GtkTreeModel *Ltreedata = gtk_tree_view_get_model(GTK_TREE_VIEW(Lliste));
-  GtkTreeSelection *Lselection = gtk_tree_view_get_selection(GTK_TREE_VIEW(Lliste));
-  GList *Lfiles = gtk_tree_selection_get_selected_rows(Lselection, &Ltreedata);
-  GList *Lrefs = NULL;
-  GList *Lnode = NULL;
-  gint Ltype;
-  guint32 Lsizenbr = 0;
-  GtkTreeIter Liter;
-  gpointer Lproxy = g_object_newv(G_TYPE_OBJECT, 0, NULL);
+  Ltreedata = gtk_tree_view_get_model(GTK_TREE_VIEW(Lliste));
+  Lselection = gtk_tree_view_get_selection(GTK_TREE_VIEW(Lliste));
+  Lfiles = gtk_tree_selection_get_selected_rows(Lselection, &Ltreedata);
+  Lrefs = NULL;
+  Lnode = NULL;
+  Lproxy = g_object_newv(G_TYPE_OBJECT, 0, NULL);
 
   for (Lnode = Lfiles; Lnode; Lnode = Lnode->next) {
     Lrefs = g_list_append(Lrefs, gtk_tree_row_reference_new_proxy(Lproxy, Ltreedata, Lnode->data));
@@ -883,10 +889,11 @@
   gboolean *Labort = (gboolean *)sc_grave_get_data(Lg, "gabort");
   GtkWidget *Lwindow = GTK_WIDGET(sc_grave_get_widget(Lg, "window_burn"));
   gint Lret;
+  GtkWidget *Lconfirm;
 
   g_assert(Labort);
 
-  GtkWidget *Lconfirm = gtk_message_dialog_new(GTK_WINDOW(Lwindow),
+  Lconfirm = gtk_message_dialog_new(GTK_WINDOW(Lwindow),
                       GTK_DIALOG_MODAL, GTK_MESSAGE_QUESTION,
                       GTK_BUTTONS_YES_NO, _("Do you really want to abort operation ?"));
 
