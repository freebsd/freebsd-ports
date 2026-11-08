--- ext/litehtml/include/litehtml/document.h.orig	2026-10-20 14:15:24 UTC
+++ ext/litehtml/include/litehtml/document.h
@@ -90,6 +90,11 @@ namespace litehtml
         uint_ptr  get_font(const font_description& descr, font_metrics* fm);
         pixel_t   render(pixel_t max_width, render_type rt = render_all);
         void      draw(uint_ptr hdc, pixel_t x, pixel_t y, const position* clip);
+        // Draw only fixed-positioned elements (position: fixed), once per
+        // page, ignoring the in-flow content. Used by paginated renderers
+        // that emit a separate pass for page furniture anchored to each
+        // page instead of the scrolling viewport.
+        void      draw_fixed(uint_ptr hdc, const position* clip);
         web_color get_def_color() const
         {
             return m_def_color;
