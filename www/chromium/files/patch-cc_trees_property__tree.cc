--- cc/trees/property_tree.cc.orig	2021-12-14 11:44:55 UTC
+++ cc/trees/property_tree.cc
@@ -1299,13 +1299,13 @@ gfx::Vector2dF ScrollTree::MaxScrollOffset(int scroll_
 
   gfx::Size clip_layer_bounds = container_bounds(scroll_node->id);
 
-  gfx::Vector2dF max_offset(
+  gfx::Vector2dF _max_offset(
       scaled_scroll_bounds.width() - clip_layer_bounds.width(),
       scaled_scroll_bounds.height() - clip_layer_bounds.height());
 
-  max_offset.Scale(1 / scale_factor);
-  max_offset.SetToMax(gfx::Vector2dF());
-  return max_offset;
+  _max_offset.Scale(1 / scale_factor);
+  _max_offset.SetToMax(gfx::Vector2dF());
+  return _max_offset;
 }
 
 gfx::SizeF ScrollTree::scroll_bounds(int scroll_node_id) const {
