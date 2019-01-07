--- third_party/blink/renderer/platform/fonts/shaping/harfbuzz_face.cc.orig	2018-12-29 14:23:27.944448000 +0100
+++ third_party/blink/renderer/platform/fonts/shaping/harfbuzz_face.cc	2018-12-29 14:29:49.494355000 +0100
@@ -139,7 +139,7 @@
 static void HarfBuzzGetGlyphHorizontalAdvances(hb_font_t* font,
                                                void* font_data,
                                                unsigned count,
-                                               hb_codepoint_t* first_glyph,
+                                               const hb_codepoint_t* first_glyph,
                                                unsigned int glyph_stride,
                                                hb_position_t* first_advance,
                                                unsigned int advance_stride,
@@ -147,7 +147,7 @@
   HarfBuzzFontData* hb_font_data =
       reinterpret_cast<HarfBuzzFontData*>(font_data);
   SkiaTextMetrics(&hb_font_data->paint_)
-      .GetGlyphWidthForHarfBuzz(count, first_glyph, glyph_stride, first_advance,
+      .GetGlyphWidthForHarfBuzz(count, const_cast<hb_codepoint_t*>(first_glyph), glyph_stride, first_advance,
                                 advance_stride);
 }
 
