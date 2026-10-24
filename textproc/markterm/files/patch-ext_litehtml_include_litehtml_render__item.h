--- ext/litehtml/include/litehtml/render_item.h.orig	2026-10-20 14:15:24 UTC
+++ ext/litehtml/include/litehtml/render_item.h
@@ -497,6 +497,7 @@ namespace litehtml
         virtual void add_inline_box(const position& /*box*/) {};
         virtual void clear_inline_boxes() {};
         void draw_stacking_context(uint_ptr hdc, pixel_t x, pixel_t y, const position* clip, bool with_positioned);
+        void draw_fixed(uint_ptr hdc, const position* clip);
         virtual void    draw_children(uint_ptr hdc, pixel_t x, pixel_t y, const position* clip, draw_flag flag,
                                       int zindex);
         // Paginated containers: tables report one box per row (y and
