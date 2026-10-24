--- ext/litehtml/src/document.cpp.orig	2026-10-20 14:15:24 UTC
+++ ext/litehtml/src/document.cpp
@@ -573,6 +573,14 @@ namespace litehtml
         }
     }
 
+    void document::draw_fixed(uint_ptr hdc, const position* clip)
+    {
+        if(m_root_render)
+        {
+            m_root_render->draw_fixed(hdc, clip);
+        }
+    }
+
     pixel_t document::to_pixels(const css_length& val, const font_metrics& metrics, pixel_t size) const
     {
         if(val.is_predefined())
