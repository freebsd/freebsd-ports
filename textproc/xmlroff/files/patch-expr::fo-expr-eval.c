--- expr/fo-expr-eval.c.orig	Mon Jan 10 13:58:52 2005
+++ expr/fo-expr-eval.c	Mon Jan 10 14:02:29 2005
@@ -1244,14 +1244,22 @@
 static void
 eval_padding_expr (FoExprContext *context)
 {
+  gchar *name;
+
   fo_expr_context_skip_blanks (context);
 
-  gchar *name = parse_ncname (context);
+  name = parse_ncname (context);
 
   if (name == NULL)
     {
       /* If not a name, then one to four <padding-width> values. */
 
+      FoDatatype *result_datatype;
+      FoDatatype *stack_first;
+      FoDatatype *stack_second;
+      FoDatatype *stack_third;
+      FoDatatype *stack_fourth;
+
       do
 	{
 	  FoDatatype *intermediate_value = NULL;
@@ -1349,10 +1357,10 @@
        * A fifth entry on the stack indicates an error.
        */
 
-      FoDatatype *result_datatype = NULL;
+      result_datatype = NULL;
 
       /* First stack entry */
-      FoDatatype *stack_first = fo_expr_context_pop_stack (context);
+      stack_first = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for top stack entry. */
       if (stack_first == NULL)
@@ -1371,7 +1379,7 @@
 	}
 
       /* Second stack entry */
-      FoDatatype *stack_second = fo_expr_context_pop_stack (context);
+      stack_second = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for second stack entry. */
       if (stack_second == NULL)
@@ -1391,7 +1399,7 @@
 	}
 
       /* third stack entry */
-      FoDatatype *stack_third = fo_expr_context_pop_stack (context);
+      stack_third = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for third stack entry. */
       if (stack_third == NULL)
@@ -1411,7 +1419,7 @@
 	}
 
       /* fourth stack entry */
-      FoDatatype *stack_fourth = fo_expr_context_pop_stack (context);
+      stack_fourth = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for fourth stack entry. */
       if (stack_fourth == NULL)
