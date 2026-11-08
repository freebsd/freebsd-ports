--- ext/litehtml/src/render_item.cpp.orig	2026-10-26 10:28:01 UTC
+++ ext/litehtml/src/render_item.cpp
@@ -1041,6 +1041,28 @@ void litehtml::render_item::draw_stacking_context(uint
     }
 }
 
+// Draw only the fixed-positioned descendants, honoring z-index order.
+// Fixed boxes are relative to the viewport (0,0), so x and y are always
+// zero here; the container maps that origin to the current page.
+void litehtml::render_item::draw_fixed(uint_ptr hdc, const position* clip)
+{
+    if(!is_visible())
+    {
+        return;
+    }
+
+    std::map<int, bool> z_indexes;
+    for(const auto& idx : m_positioned)
+    {
+        z_indexes[idx->src_el()->css().get_z_index()];
+    }
+
+    for(const auto& ix : z_indexes)
+    {
+        draw_children(hdc, 0_px, 0_px, clip, draw_fixed_only, ix.first);
+    }
+}
+
 // Compute absolute document-space bounds for this subtree: each item
 // stores the absolute top of its box and the absolute bottom of its
 // whole subtree (including margins and overflowing children). The
@@ -1211,6 +1233,19 @@ void litehtml::render_item::draw_children(uint_ptr hdc
                     process = false;
                 }
                 break;
+            case draw_fixed_only:
+                // Draw nothing for in-flow or absolutely positioned
+                // elements; only fixed boxes, and only via the positioned
+                // branch below. Fixed elements ignore x/y, so they are
+                // drawn relative to the (0,0) viewport origin.
+                if(el->src_el()->is_positioned() && el->src_el()->css().get_position() == element_position_fixed &&
+                   el->src_el()->css().get_z_index() == zindex)
+                {
+                    el->src_el()->draw(hdc, 0_px, 0_px, clip, el);
+                    el->draw_stacking_context(hdc, 0_px, 0_px, clip, true);
+                    process = false;
+                }
+                break;
             case draw_block:
                 if(!el->src_el()->is_inline() && el->src_el()->css().get_float() == float_none &&
                    !el->src_el()->is_positioned())
@@ -1245,7 +1280,7 @@ void litehtml::render_item::draw_children(uint_ptr hdc
 
             if(process)
             {
-                if(flag == draw_positioned)
+                if(flag == draw_positioned || flag == draw_fixed_only)
                 {
                     if(!el->src_el()->is_positioned())
                     {
