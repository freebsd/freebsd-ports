--- src/dialogs/dialog-sheet-order.c.orig   Thu Sep 25 11:53:53 2003
+++ src/dialogs/dialog-sheet-order.c        Thu Sep 25 11:54:25 2003
@@ -106,6 +106,8 @@
 static gint
 location_of_iter (GtkTreeIter  *iter, GtkListStore *model)
 {
+       gint    loc;
+
        /* Note: in gtk 2.2 we could just do: */
 /*     gchar* path = gtk_tree_model_get_string_from_iter */
 /*             (GTK_TREE_MODEL (model), iter); */
@@ -117,7 +119,7 @@
        gtk_tree_path_free (treepath);
        /* end of gtk 2.0 code */
  
-       gint loc = atoi(path);
+       loc = atoi(path);
  
        g_free (path);
