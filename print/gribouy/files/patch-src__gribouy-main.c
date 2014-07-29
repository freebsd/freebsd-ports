--- src/gribouy-main.c.orig	Thu Nov 20 04:01:59 2003
+++ src/gribouy-main.c	Thu Nov 20 04:03:00 2003
@@ -660,10 +660,11 @@
 static GtkTreeIter *
 model_append (const gchar *key, gpointer *value, GtkListStore **user_data)
 {
-	g_return_if_fail (GTK_IS_LIST_STORE (*user_data));
 	GtkTreeIter *iter;
 	GtkTreeSelection *selection;
 
+	g_return_if_fail (GTK_IS_LIST_STORE (*user_data));
+
 	iter = g_new0 (GtkTreeIter, 1);
 	gtk_list_store_append (GTK_LIST_STORE (*user_data), iter);
 	gtk_list_store_set (GTK_LIST_STORE (*user_data),
@@ -679,8 +680,9 @@
 static void
 construct_model (gchar *key, gpointer *value, GtkListStore **user_data)
 {
-	g_return_if_fail (GTK_IS_LIST_STORE (*user_data));
 	GtkTreeIter iter;
+
+	g_return_if_fail (GTK_IS_LIST_STORE (*user_data));
 
 	gtk_list_store_append (GTK_LIST_STORE (*user_data), &iter);
 	gtk_list_store_set (GTK_LIST_STORE (*user_data),
