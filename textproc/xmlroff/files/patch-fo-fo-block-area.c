--- fo/fo-block-area.c.orig	Mon Jan 30 21:55:41 2006
+++ fo/fo-block-area.c	Mon Jan 30 21:56:28 2006
@@ -222,6 +222,7 @@
   GSList *line_heights = NULL;
   gint line_count, line_index;
   gint cumulative_height = 0;
+  gchar *font_family = NULL;
 
   g_return_if_fail (block != NULL);
   g_return_if_fail (FO_IS_BLOCK (block));
@@ -312,7 +313,7 @@
   font_desc =
     fo_font_desc_copy (fo_doc_get_font_desc (fo_doc));
 
-  gchar *font_family = fo_string_get_value (fo_property_get_value (fo_block_get_font_family (block)));
+  font_family = fo_string_get_value (fo_property_get_value (fo_block_get_font_family (block)));
   fo_font_desc_set_family (font_desc, font_family);
   g_free (font_family);
     
