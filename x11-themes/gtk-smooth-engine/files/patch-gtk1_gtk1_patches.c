--- gtk1/gtk1_patches.c.orig	Sun Oct 17 02:18:35 2004
+++ gtk1/gtk1_patches.c	Sun Oct 17 02:21:21 2004
@@ -934,6 +934,8 @@
     slider_length = SCALE_SLIDER_LENGTH(widget->style);    
   }
 
+  
+
   _scale_calc_request (widget, slider_width, slider_length, stepper_size, trough_border, stepper_spacing, &range_rect);
 
   requisition->width = MAX(requisition->width, range_rect.width);
@@ -1214,7 +1216,8 @@
   GtkRange *range;
   gint slider_width, slider_length, stepper_size, trough_border, stepper_spacing;
   GdkRectangle range_rect;
-    
+  int size1, size2;
+  
   g_return_if_fail (widget != NULL);
   g_return_if_fail (GTK_IS_SCROLLBAR (widget));
   g_return_if_fail (requisition != NULL);
@@ -1229,8 +1232,8 @@
     slider_length = SCROLLBAR_MIN_SLIDER_LENGTH(widget->style);    
   }
 
-  int size1 = (slider_length + stepper_size + stepper_spacing + trough_border) * 2;
-  int size2 = (slider_width + trough_border * 2);
+  size1 = (slider_length + stepper_size + stepper_spacing + trough_border) * 2;
+  size2 = (slider_width + trough_border * 2);
    
   if (GTK_IS_HSCROLLBAR(widget)) {
     requisition->width = size1;
