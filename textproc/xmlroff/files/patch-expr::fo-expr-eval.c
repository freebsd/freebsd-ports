--- expr/fo-expr-eval.c.orig	Mon Feb 28 20:55:34 2005
+++ expr/fo-expr-eval.c	Thu Mar  3 10:55:21 2005
@@ -1240,14 +1240,22 @@
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
@@ -1345,10 +1353,10 @@
        * A fifth entry on the stack indicates an error.
        */
 
-      FoDatatype *result_datatype = NULL;
+      result_datatype = NULL;
 
       /* First stack entry */
-      FoDatatype *stack_first = fo_expr_context_pop_stack (context);
+      stack_first = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for top stack entry. */
       if (stack_first == NULL)
@@ -1367,7 +1375,7 @@
 	}
 
       /* Second stack entry */
-      FoDatatype *stack_second = fo_expr_context_pop_stack (context);
+      stack_second = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for second stack entry. */
       if (stack_second == NULL)
@@ -1387,7 +1395,7 @@
 	}
 
       /* third stack entry */
-      FoDatatype *stack_third = fo_expr_context_pop_stack (context);
+      stack_third = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for third stack entry. */
       if (stack_third == NULL)
@@ -1407,7 +1415,7 @@
 	}
 
       /* fourth stack entry */
-      FoDatatype *stack_fourth = fo_expr_context_pop_stack (context);
+      stack_fourth = fo_expr_context_pop_stack (context);
 
       /* Handle possible conditions for fourth stack entry. */
       if (stack_fourth == NULL)
@@ -1575,6 +1583,12 @@
 static void
 eval_border_color_expr (FoExprContext *context)
 {
+    FoDatatype *result_datatype = NULL;
+    FoDatatype *stack_first;
+    FoDatatype *stack_second;
+    FoDatatype *stack_third;
+    FoDatatype *stack_fourth;
+
     /* If not 'inherit', then one to four <color> or 'transparent' values. */
     do
     {
@@ -1658,10 +1672,10 @@
      * A fifth entry on the stack indicates an error.
      */
 
-    FoDatatype *result_datatype = NULL;
+    result_datatype = NULL;
 
     /* First stack entry */
-    FoDatatype *stack_first = fo_expr_context_pop_stack (context);
+    stack_first = fo_expr_context_pop_stack (context);
 
     /* Handle possible conditions for top stack entry. */
     if (stack_first == NULL)
@@ -1680,7 +1694,7 @@
     }
 
     /* Second stack entry */
-    FoDatatype *stack_second = fo_expr_context_pop_stack (context);
+    stack_second = fo_expr_context_pop_stack (context);
 
     /* Handle possible conditions for second stack entry. */
     if (stack_second == NULL)
@@ -1700,7 +1714,7 @@
     }
 
     /* third stack entry */
-    FoDatatype *stack_third = fo_expr_context_pop_stack (context);
+    stack_third = fo_expr_context_pop_stack (context);
 
     /* Handle possible conditions for third stack entry. */
     if (stack_third == NULL)
@@ -1720,7 +1734,7 @@
     }
 
     /* fourth stack entry */
-    FoDatatype *stack_fourth = fo_expr_context_pop_stack (context);
+    stack_fourth = fo_expr_context_pop_stack (context);
 
     /* Handle possible conditions for fourth stack entry. */
     if (stack_fourth == NULL)
