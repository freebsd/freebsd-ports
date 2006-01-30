--- property/fo-property-dominant-baseline.c.orig	Mon Jan 30 22:02:19 2006
+++ property/fo-property-dominant-baseline.c	Mon Jan 30 22:03:47 2006
@@ -453,12 +453,15 @@
 
   if (dominant_baseline != FO_ENUM_ENUM_RESET_SIZE)
     {
+      gchar *font_family = NULL;
+      PangoAttribute *pango_attr = NULL;
+
       PangoBaseline pango_dominant_baseline =
 	fo_property_dominant_baseline_to_pango_baseline (dominant_baseline);
   
       font_desc = pango_font_description_new ();
 
-      gchar *font_family = fo_string_get_value (fo_property_get_value (fo_context_get_font_family (context)));
+      font_family = fo_string_get_value (fo_property_get_value (fo_context_get_font_family (context)));
       pango_font_description_set_family (font_desc, font_family);
       g_free (font_family);
 
@@ -473,7 +476,7 @@
       pango_font_description_set_variant (font_desc,
 					  fo_enum_get_value (fo_property_get_value (fo_context_get_font_variant (context))));
 
-      PangoAttribute *pango_attr = pango_attr_dominant_baseline_new (pango_dominant_baseline,
+      pango_attr = pango_attr_dominant_baseline_new (pango_dominant_baseline,
 								     font_desc);
       pango_font_description_free (font_desc);
       return pango_attr;
