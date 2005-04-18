--- src/callbacks.c.orig	Sat Feb 12 17:41:07 2005
+++ src/callbacks.c	Mon Apr 18 11:13:00 2005
@@ -392,6 +392,14 @@
 /* enlever des fichiers a graver */
 void gtk_data_removefiles(GtkWidget *Abtn, gpointer Adata)
 {
+  GtkTreeModel *Ltreedata;
+  GtkTreeSelection *Lselection;
+  GList *Lfiles, *Lrefs, *Lnode;
+  gint Ltype;
+  guint32 Lsizenbr = 0;
+  GtkTreeIter Liter;
+  gpointer Lproxy;
+
   GHashTable *Lhash = (GHashTable *)Adata;
   GtkTreeView *Lliste = GTK_TREE_VIEW(g_hash_table_lookup(Lhash, "_current_list"));
 //  gchar *Lprefix = (!strcmp(glade_get_widget_name(Lliste), "LISTEDATA") ? "data" : "dvddata");
@@ -405,15 +413,12 @@
 #if 0  
   GtkTreeIter *Literboot = g_hash_table_lookup(Lhash, "file_imageboot");
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
@@ -860,11 +865,12 @@
   GHashTable *Lhash = (GHashTable *) Adata;
   gboolean *Labort = (gboolean *)g_hash_table_lookup(Lhash, "gabort");
   GtkWidget *Lwindow = GTK_WIDGET(g_hash_table_lookup(Lhash, "window_burn"));
+  GtkWidget *Lconfirm;
   gint Lret;
 
   g_assert(Labort);
 
-  GtkWidget *Lconfirm = gtk_message_dialog_new(GTK_WINDOW(Lwindow),
+  Lconfirm = gtk_message_dialog_new(GTK_WINDOW(Lwindow),
                       GTK_DIALOG_MODAL, GTK_MESSAGE_QUESTION,
                       GTK_BUTTONS_YES_NO, _("Do you really want to abort operation ?"));
 
