--- fo-context-util.c.orig	Mon May  2 04:22:17 2005
+++ fo-context-util.c	Wed Jun 15 01:28:36 2005
@@ -926,6 +926,8 @@
   FoContextPropertyFunc absolute_func;
   FoContextPropertyFunc relative_func;
   FoDatatype *shorthand_component;
+  FoDatatype *padding_tblr;
+  FoProperty *padding;
 
   g_return_if_fail (current_context != NULL);
   g_return_if_fail (parent_context != NULL);
@@ -937,9 +939,9 @@
 			0);
   */
 
-  FoDatatype *padding_tblr = NULL;
+  padding_tblr = NULL;
 
-  FoProperty *padding = fo_context_get_padding (current_context);
+  padding = fo_context_get_padding (current_context);
 
   if (padding != NULL)
     {
@@ -1207,6 +1209,31 @@
   FoProperty *prop_color;
   FoDatatype *initial_color;
 
+  FoProperty *border_color;
+  FoDatatype *border_color_tblr;
+  FoDatatype *border_color_component;
+  FoProperty *border_style;
+  FoDatatype *border_style_tblr;
+  FoDatatype *border_style_component;
+  FoProperty *border_width;
+  FoDatatype *border_width_tblr;
+  FoDatatype *border_width_component;
+  FoProperty *border;
+  FoDatatype *border_wsc;
+  FoDatatype *border_component;
+  FoProperty *border_bottom;
+  FoDatatype *border_bottom_wsc;
+  FoDatatype *border_bottom_component;
+  FoProperty *border_left;
+  FoDatatype *border_left_wsc;
+  FoDatatype *border_left_component;
+  FoProperty *border_right;
+  FoDatatype *border_right_wsc;
+  FoDatatype *border_right_component;
+  FoProperty *border_top;
+  FoDatatype *border_top_wsc;
+  FoDatatype *border_top_component;
+
   g_return_if_fail (current_context != NULL);
   g_return_if_fail (parent_context != NULL);
   g_return_if_fail (FO_IS_CONTEXT (current_context));
@@ -1223,93 +1250,93 @@
 
   initial_color = fo_property_get_value (prop_color);
 
-  FoProperty *border_color = fo_context_get_border_color (current_context);
+  border_color = fo_context_get_border_color (current_context);
 
-  FoDatatype *border_color_tblr = NULL;
+  border_color_tblr = NULL;
 
   if (border_color != NULL)
     {
       border_color_tblr = fo_property_get_value (border_color);
     }
 
-  FoDatatype *border_color_component;
+  border_color_component;
 
-  FoProperty *border_style = fo_context_get_border_style (current_context);
+  border_style = fo_context_get_border_style (current_context);
 
-  FoDatatype *border_style_tblr = NULL;
+  border_style_tblr = NULL;
 
   if (border_style != NULL)
     {
       border_style_tblr = fo_property_get_value (border_style);
     }
 
-  FoDatatype *border_style_component;
+  border_style_component;
 
-  FoProperty *border_width = fo_context_get_border_width (current_context);
+  border_width = fo_context_get_border_width (current_context);
 
-  FoDatatype *border_width_tblr = NULL;
+  border_width_tblr = NULL;
 
   if (border_width != NULL)
     {
       border_width_tblr = fo_property_get_value (border_width);
     }
 
-  FoDatatype *border_width_component;
+  border_width_component;
 
-  FoProperty *border = fo_context_get_border (current_context);
+  border = fo_context_get_border (current_context);
 
-  FoDatatype *border_wsc = NULL;
+  border_wsc = NULL;
 
   if (border != NULL)
     {
       border_wsc = fo_property_get_value (border);
     }
 
-  FoDatatype *border_component;
+  border_component;
 
-  FoProperty *border_bottom = fo_context_get_border_bottom (current_context);
+  border_bottom = fo_context_get_border_bottom (current_context);
 
-  FoDatatype *border_bottom_wsc = NULL;
+  border_bottom_wsc = NULL;
 
   if (border_bottom != NULL)
     {
       border_bottom_wsc = fo_property_get_value (border_bottom);
     }
 
-  FoDatatype *border_bottom_component;
+  border_bottom_component;
 
-  FoProperty *border_left = fo_context_get_border_left (current_context);
+  border_left = fo_context_get_border_left (current_context);
 
-  FoDatatype *border_left_wsc = NULL;
+  border_left_wsc = NULL;
 
   if (border_left != NULL)
     {
       border_left_wsc = fo_property_get_value (border_left);
     }
 
-  FoDatatype *border_left_component;
+  border_left_component;
 
-  FoProperty *border_right = fo_context_get_border_right (current_context);
+  border_right = fo_context_get_border_right (current_context);
 
-  FoDatatype *border_right_wsc = NULL;
+  border_right_wsc = NULL;
 
   if (border_right != NULL)
     {
       border_right_wsc = fo_property_get_value (border_right);
     }
 
-  FoDatatype *border_right_component;
+  border_right_component;
 
-  FoProperty *border_top = fo_context_get_border_top (current_context);
+  border_top = fo_context_get_border_top (current_context);
 
-  FoDatatype *border_top_wsc = NULL;
+  border_top_wsc = NULL;
 
   if (border_top != NULL)
     {
       border_top_wsc = fo_property_get_value (border_top);
     }
 
-  FoDatatype *border_top_component;
+  border_top_component;
 
   /* left = start*/
   /* style */
