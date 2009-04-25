--- gfx/thebes/src/gfxPangoFonts.cpp.orig	2009-04-17 14:17:44.639661606 +0200
+++ gfx/thebes/src/gfxPangoFonts.cpp	2009-04-17 14:20:24.044400205 +0200
@@ -1803,12 +1803,11 @@
 
 static PangoFcFont *
 gfx_pango_font_map_create_font(PangoFcFontMap *fontmap,
-                               PangoContext *context,
-                               const PangoFontDescription *desc,
-                               FcPattern *pattern)
+                               PangoFcFontKey *fontkey)
 {
-    return PANGO_FC_FONT(g_object_new(GFX_TYPE_PANGO_FC_FONT,
-                                      "pattern", pattern, NULL));
+     const FcPattern *p_pattern = pango_fc_font_key_get_pattern(fontkey);
+     return PANGO_FC_FONT(g_object_new(GFX_TYPE_PANGO_FC_FONT,
+                                       "pattern", p_pattern, NULL));
 }
 
 static void
@@ -1828,9 +1827,8 @@
     // context_key_* virtual functions are only necessary if we want to
     // dynamically respond to changes in the screen cairo_font_options_t.
 
-    // context_substitute and get_font are not likely to be used but
+    // get_font is not likely to be used but
     //   implemented because the class makes them available.
-    fcfontmap_class->context_substitute = gfx_pango_font_map_context_substitute;
     fcfontmap_class->create_font = gfx_pango_font_map_create_font;
 }
 
