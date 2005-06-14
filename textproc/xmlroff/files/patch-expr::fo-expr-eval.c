--- expr/fo-expr-eval.c.orig	Tue Apr 26 07:13:16 2005
+++ expr/fo-expr-eval.c	Wed Jun 15 01:07:29 2005
@@ -1283,6 +1283,9 @@
    */
 
   FoDatatype *result_datatype = NULL;
+  FoDatatype *stack_second = NULL;
+  FoDatatype *stack_third = NULL;
+  FoDatatype *stack_fourth = NULL;
 
   /* First stack entry */
   FoDatatype *stack_first = fo_expr_context_pop_stack (context);
@@ -1304,7 +1307,7 @@
     }
 
   /* Second stack entry */
-  FoDatatype *stack_second = fo_expr_context_pop_stack (context);
+  stack_second = fo_expr_context_pop_stack (context);
 
   /* Handle possible conditions for second stack entry. */
   if (stack_second == NULL)
@@ -1324,7 +1327,7 @@
     }
 
   /* third stack entry */
-  FoDatatype *stack_third = fo_expr_context_pop_stack (context);
+  stack_third = fo_expr_context_pop_stack (context);
 
   /* Handle possible conditions for third stack entry. */
   if (stack_third == NULL)
@@ -1344,7 +1347,7 @@
     }
 
   /* fourth stack entry */
-  FoDatatype *stack_fourth = fo_expr_context_pop_stack (context);
+  stack_fourth = fo_expr_context_pop_stack (context);
 
   /* Handle possible conditions for fourth stack entry. */
   if (stack_fourth == NULL)
@@ -1383,9 +1386,11 @@
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
@@ -1745,11 +1750,12 @@
     /* If not 'inherit', then one to four <color> or 'transparent' values. */
     do
     {
+	gchar *name;
 	FoDatatype *intermediate_value = NULL;
   
 	fo_expr_context_skip_blanks (context);
 
-	gchar *name = parse_ncname (context);
+	name = parse_ncname (context);
 
 	if (name != NULL)
 	  {
@@ -1902,6 +1908,8 @@
   FoDatatype *width_datatype = NULL;
   FoDatatype *style_datatype = NULL;
   FoDatatype *color_datatype = NULL;
+  FoDatatype *stack_second;
+  FoDatatype *stack_third;
 
   /* First stack entry */
   FoDatatype *stack_first = fo_expr_context_pop_stack (context);
@@ -1941,7 +1949,7 @@
     }
 
   /* Second stack entry */
-  FoDatatype *stack_second = fo_expr_context_pop_stack (context);
+  stack_second = fo_expr_context_pop_stack (context);
 
   /* Handle possible conditions for second stack entry. */
   if (stack_second == NULL)
@@ -1984,7 +1992,7 @@
     }
 
   /* Third stack entry */
-  FoDatatype *stack_third = fo_expr_context_pop_stack (context);
+  stack_third = fo_expr_context_pop_stack (context);
 
   /* Handle possible conditions for third stack entry. */
   if (stack_third == NULL)
