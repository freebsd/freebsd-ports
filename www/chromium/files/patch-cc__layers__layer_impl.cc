--- cc/layers/layer_impl.cc.orig	2015-01-20 21:28:14 UTC
+++ cc/layers/layer_impl.cc
@@ -1239,21 +1239,23 @@
                                scale_factor * scaled_scroll_bounds.height());
   scaled_scroll_bounds = gfx::ToFlooredSize(scaled_scroll_bounds);
 
-  gfx::ScrollOffset max_offset(
+  // (rene) prevent name collision with /usr/include/vm/vm_map.h on FreeBSD
+  // which also defines max_offset
+  gfx::ScrollOffset _max_offset(
       scaled_scroll_bounds.width() - scroll_clip_layer_->bounds().width(),
       scaled_scroll_bounds.height() - scroll_clip_layer_->bounds().height());
   // We need the final scroll offset to be in CSS coords.
-  max_offset.Scale(1 / scale_factor);
-  max_offset.SetToMax(gfx::ScrollOffset());
-  return max_offset;
+  _max_offset.Scale(1 / scale_factor);
+  _max_offset.SetToMax(gfx::ScrollOffset());
+  return _max_offset;
 }
 
 gfx::Vector2dF LayerImpl::ClampScrollToMaxScrollOffset() {
-  gfx::ScrollOffset max_offset = MaxScrollOffset();
+  gfx::ScrollOffset _max_offset = MaxScrollOffset();
   gfx::ScrollOffset old_offset = TotalScrollOffset();
   gfx::ScrollOffset clamped_offset = old_offset;
 
-  clamped_offset.SetToMin(max_offset);
+  clamped_offset.SetToMin(_max_offset);
   clamped_offset.SetToMax(gfx::ScrollOffset());
   gfx::Vector2dF delta = clamped_offset.DeltaFrom(old_offset);
   if (!delta.IsZero())
