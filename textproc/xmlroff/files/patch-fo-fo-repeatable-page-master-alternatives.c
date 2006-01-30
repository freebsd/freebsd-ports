--- fo/fo-repeatable-page-master-alternatives.c.orig	Mon Jan 30 21:58:24 2006
+++ fo/fo-repeatable-page-master-alternatives.c	Mon Jan 30 21:58:43 2006
@@ -131,12 +131,13 @@
                                                          GError **error)
 {
   GError *tmp_error = NULL;
+  FoNode *child_node = NULL;
 
   g_return_val_if_fail (fo != NULL, TRUE);
   g_return_val_if_fail (FO_IS_REPEATABLE_PAGE_MASTER_ALTERNATIVES (fo), TRUE);
   g_return_val_if_fail (error == NULL || *error == NULL, TRUE);
 
-  FoNode *child_node = fo_node_first_child (FO_NODE (fo));
+  child_node = fo_node_first_child (FO_NODE (fo));
 
   while (child_node)
     {
