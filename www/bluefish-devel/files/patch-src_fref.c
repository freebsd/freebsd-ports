--- src/fref.c.orig	Fri Oct 31 22:36:50 2003
+++ src/fref.c	Sun Nov  9 17:10:58 2003
@@ -1784,9 +1784,9 @@
 } Tfref_cleanup;
 
 static guint fref_idle_cleanup(Tfref_cleanup *data) {
-	DEBUG_MSG("fref_idle_cleanup, started for data=%s\n",data->cat);
 	GtkTreeIter iter;
 	gboolean cont = TRUE;
+	DEBUG_MSG("fref_idle_cleanup, started for data=%s\n",data->cat);
 	gtk_tree_model_get_iter_first(GTK_TREE_MODEL(FREFDATA(main_v->frefdata)->store),&iter);
 	while (cont) {
 		gchar *str;
