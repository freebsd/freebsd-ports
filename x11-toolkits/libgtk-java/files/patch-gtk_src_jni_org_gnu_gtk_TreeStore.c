--- gtk/src/jni/org_gnu_gtk_TreeStore.c.orig	Sun Mar  7 00:56:20 2004
+++ gtk/src/jni/org_gnu_gtk_TreeStore.c	Sun Mar  7 00:57:03 2004
@@ -388,7 +388,7 @@
     *env, jclass cls, jint treeStore, jint parent, jint sibling) 
 {
     GtkTreeStore *treeStore_g = (GtkTreeStore *)treeStore;
-    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));;
+    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));
     GtkTreeIter *parent_g = (GtkTreeIter *)parent;
     GtkTreeIter *sibling_g = (GtkTreeIter *)sibling;
     gtk_tree_store_insert_before (treeStore_g, iter_g, parent_g, sibling_g);
@@ -404,7 +404,7 @@
     jclass cls, jint treeStore, jint parent, jint sibling) 
 {
     GtkTreeStore *treeStore_g = (GtkTreeStore *)treeStore;
-    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));;
+    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));
     GtkTreeIter *parent_g = (GtkTreeIter *)parent;
     GtkTreeIter *sibling_g = (GtkTreeIter *)sibling;
 	gtk_tree_store_insert_after (treeStore_g, iter_g, parent_g, sibling_g);
@@ -420,7 +420,7 @@
     jclass cls, jint treeStore, jint parent) 
 {
     GtkTreeStore *treeStore_g = (GtkTreeStore *)treeStore;
-    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));;
+    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));
     GtkTreeIter *parent_g = (GtkTreeIter *)parent;
 	gtk_tree_store_prepend (treeStore_g, iter_g, parent_g);
     return (jint)iter_g;
@@ -435,7 +435,7 @@
     cls, jint treeStore, jint parent) 
 {
     GtkTreeStore *treeStore_g = (GtkTreeStore *)treeStore;
-    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));;
+    GtkTreeIter *iter_g = (GtkTreeIter *)g_malloc(sizeof(GtkTreeIter));
     GtkTreeIter *parent_g = (GtkTreeIter *)parent;
 	gtk_tree_store_append (treeStore_g, iter_g, parent_g);
     return (jint)iter_g;
