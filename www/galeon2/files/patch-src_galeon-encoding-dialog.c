--- src/galeon-encoding-dialog.c.orig	Sat Jul  3 16:45:02 2004
+++ src/galeon-encoding-dialog.c	Sat Jul  3 16:45:11 2004
@@ -282,10 +282,10 @@
 tree_view_selection_changed_cb (GtkTreeSelection *selection, 
 				GaleonEncodingDialog *dialog)
 {
-	if (dialog->priv->update_tag == TRUE) return;
-
 	GtkTreeModel *model;
 	GtkTreeIter iter;
+
+	if (dialog->priv->update_tag == TRUE) return;
 
 	if (gtk_tree_selection_get_selected (selection, &model, &iter))
 	{
