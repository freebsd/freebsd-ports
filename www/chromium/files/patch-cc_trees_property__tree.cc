--- cc/trees/property_tree.cc.orig	2020-07-07 21:58:11 UTC
+++ cc/trees/property_tree.cc
@@ -1245,13 +1245,13 @@ gfx::ScrollOffset ScrollTree::MaxScrollOffset(int scro
 
   gfx::Size clip_layer_bounds = container_bounds(scroll_node->id);
 
-  gfx::ScrollOffset max_offset(
+  gfx::ScrollOffset _max_offset(
       scaled_scroll_bounds.width() - clip_layer_bounds.width(),
       scaled_scroll_bounds.height() - clip_layer_bounds.height());
 
-  max_offset.Scale(1 / scale_factor);
-  max_offset.SetToMax(gfx::ScrollOffset());
-  return max_offset;
+  _max_offset.Scale(1 / scale_factor);
+  _max_offset.SetToMax(gfx::ScrollOffset());
+  return _max_offset;
 }
 
 gfx::SizeF ScrollTree::scroll_bounds(int scroll_node_id) const {
