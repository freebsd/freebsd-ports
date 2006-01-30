--- property/fo-property-font-family.c.orig	Mon Jan 30 23:43:52 2006
+++ property/fo-property-font-family.c	Mon Jan 30 23:45:58 2006
@@ -475,13 +475,14 @@
 fo_property_font_family_new_attr (FoProperty *property)
 {
   gchar *pango_font_family;
+  PangoAttribute *pango_attr = NULL;
 
   g_return_val_if_fail (FO_IS_PROPERTY_FONT_FAMILY (property), NULL);
 
   pango_font_family =
     fo_string_get_value (property->value);
 
-  PangoAttribute *pango_attr = pango_attr_family_new (pango_font_family);
+  pango_attr = pango_attr_family_new (pango_font_family);
 
   g_free (pango_font_family);
 
