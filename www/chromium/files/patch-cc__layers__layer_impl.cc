--- cc/layers/layer_impl.cc.orig	2015-04-18 22:47:03.000000000 +0200
+++ cc/layers/layer_impl.cc	2015-04-18 22:52:19.000000000 +0200
@@ -1230,13 +1230,15 @@
       gfx::ToFlooredSize(gfx::ScaleSize(BoundsForScrolling(), scale_factor));
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
 
 gfx::ScrollOffset LayerImpl::ClampScrollOffsetToLimits(
