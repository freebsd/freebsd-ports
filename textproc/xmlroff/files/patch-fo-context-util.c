--- fo-context-util.c.orig	Mon Jan 10 14:05:08 2005
+++ fo-context-util.c	Mon Jan 10 14:05:42 2005
@@ -922,6 +922,8 @@
   FoContextPropertyFunc absolute_func;
   FoContextPropertyFunc relative_func;
   FoDatatype *shorthand_component;
+  FoDatatype *padding_tblr;
+  FoProperty *padding;
 
   g_return_if_fail (current_context != NULL);
   g_return_if_fail (parent_context != NULL);
@@ -933,9 +935,9 @@
 			0);
   */
 
-  FoDatatype *padding_tblr = NULL;
+  padding_tblr = NULL;
 
-  FoProperty *padding = fo_context_get_padding (current_context);
+  padding = fo_context_get_padding (current_context);
 
   if (padding != NULL)
     {
