--- cc/trees/property_tree.cc.orig	2016-05-27 18:17:35.339678000 -0400
+++ cc/trees/property_tree.cc	2016-05-27 18:29:09.640334000 -0400
@@ -1488,13 +1488,13 @@
 
   gfx::Size clip_layer_bounds = scroll_clip_layer_bounds(scroll_node->id);
 
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
 
 gfx::Size ScrollTree::scroll_clip_layer_bounds(int scroll_node_id) const {
