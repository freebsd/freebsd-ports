--- gtk1/gtk1_patches.c.orig	Sat Jan  3 18:40:36 2004
+++ gtk1/gtk1_patches.c	Sat Jan  3 18:41:07 2004
@@ -1197,6 +1197,7 @@
   GtkRange *range;
   gint slider_width, slider_length, stepper_size, trough_border, stepper_spacing;
   GdkRectangle range_rect;
+  int size1, size2;
     
   g_return_if_fail (widget != NULL);
   g_return_if_fail (GTK_IS_SCROLLBAR (widget));
@@ -1212,8 +1213,8 @@
     slider_length = SCROLLBAR_MIN_SLIDER_LENGTH(widget->style);    
   }
 
-  int size1 = (slider_length + stepper_size + stepper_spacing + trough_border) * 2;
-  int size2 = (slider_width + trough_border * 2);
+  size1 = (slider_length + stepper_size + stepper_spacing + trough_border) * 2;
+  size2 = (slider_width + trough_border * 2);
    
   if (GTK_IS_HSCROLLBAR(widget)) {
     requisition->width = size1;
