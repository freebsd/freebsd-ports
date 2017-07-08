--- cc/trees/property_tree.cc.orig	2017-06-05 19:03:01 UTC
+++ cc/trees/property_tree.cc
@@ -1256,13 +1256,13 @@ gfx::ScrollOffset ScrollTree::MaxScrollOffset(int scro
 
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
 
 void ScrollTree::OnScrollOffsetAnimated(int layer_id,
