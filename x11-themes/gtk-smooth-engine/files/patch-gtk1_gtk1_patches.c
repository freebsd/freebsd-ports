--- engines/gtk1/src/smooth_gtk1_patches.c.orig	Mon Jan 17 15:03:36 2005
+++ engines/gtk1/src/smooth_gtk1_patches.c	Mon May  1 15:48:50 2006
@@ -959,6 +959,8 @@
     slider_length = SCALE_SLIDER_LENGTH(widget->style);    
   }
 
+  
+
   _scale_calc_request (widget, slider_width, slider_length, stepper_size, trough_border, stepper_spacing, &range_rect);
 
   requisition->width = MAX(requisition->width, range_rect.width);
@@ -1237,6 +1239,7 @@
 {
   GtkRange *range;
   gint slider_width = 15, slider_length = 30, stepper_size = 15, trough_border = 2, stepper_spacing = 2;
+  int size1, size2;
     
   g_return_if_fail (widget != NULL);
   g_return_if_fail (GTK_IS_SCROLLBAR (widget));
@@ -1252,8 +1255,8 @@
     slider_length = SCROLLBAR_MIN_SLIDER_LENGTH(widget->style);    
   }
 
-  int size1 = (slider_length + stepper_size + stepper_spacing + trough_border) * 2;
-  int size2 = (slider_width + trough_border * 2);
+  size1 = (slider_length + stepper_size + stepper_spacing + trough_border) * 2;
+  size2 = (slider_width + trough_border * 2);
    
   if (GTK_IS_HSCROLLBAR(widget)) {
     requisition->width = size1;
