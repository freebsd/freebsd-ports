--- area/fo-area-layout.c.orig	Mon Jan 10 13:51:32 2005
+++ area/fo-area-layout.c	Mon Jan 10 13:52:41 2005
@@ -543,6 +543,7 @@
 		       PANGO_SCALE - line_first_pre_height) ||
 		      line_index == pre_widow_max - 1)
 		    {
+			gboolean retain_padding_before;
 #if defined(LIBFO_DEBUG) && 0
 		      g_message ("layout_split_before_height:: Break:: line: %d",
 				 line_index);
@@ -558,7 +559,7 @@
 						     0.0);
 		      fo_area_area_set_border_before (new_area,
 						      0.0);
-		      gboolean retain_padding_before =
+		      retain_padding_before =
 			fo_length_cond_get_condity (fo_property_get_value (fo_block_get_padding_before (area->generated_by)));
 
 		      if (!retain_padding_before)
@@ -824,10 +825,12 @@
 fo_area_layout_get_line_height (FoArea *fo_area_layout,
 				gint    line_number)
 {
+  FoAreaLayout *layout;
+
   g_return_val_if_fail (fo_area_layout != NULL, 0.0);
   g_return_val_if_fail (FO_IS_AREA_LAYOUT (fo_area_layout), 0.0);
 
-  FoAreaLayout *layout = FO_AREA_LAYOUT (fo_area_layout);
+  layout = FO_AREA_LAYOUT (fo_area_layout);
 
   return
     (gdouble) GPOINTER_TO_INT (g_slist_nth_data (layout->line_heights,
