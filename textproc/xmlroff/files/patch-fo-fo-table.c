--- fo/fo-table.c.orig	Mon Jan 30 21:59:46 2006
+++ fo/fo-table.c	Mon Jan 30 22:00:08 2006
@@ -1700,6 +1700,7 @@
   FoDatatype *column_proportional = NULL;
   FoContext  *parent_context = NULL;
   GError *tmp_error = NULL;
+  gchar *string_value = NULL;
 
   g_return_val_if_fail (error == NULL || *error == NULL, NULL);
 
@@ -1715,7 +1716,7 @@
   parent_context =
     fo_fo_get_context (FO_FO (fo_node_parent (FO_NODE (table_column))));
 
-  gchar *string_value = fo_string_get_value (column_width_string);
+  string_value = fo_string_get_value (column_width_string);
   column_proportional =
     fo_expr_eval (string_value,
 		  "column-width",
