--- thunar/thunar-list-model.c.orig	2020-05-24 12:27:08 UTC
+++ thunar/thunar-list-model.c
@@ -705,7 +705,7 @@ thunar_list_model_get_value (GtkTreeModel *model,
   _thunar_return_if_fail (iter->stamp == (THUNAR_LIST_MODEL (model))->stamp);
 
   file = g_sequence_get (iter->user_data);
-  _thunar_assert (THUNAR_IS_FILE (file));
+  _thunar_return_if_fail (THUNAR_IS_FILE (file));
 
   switch (column)
     {
