--- ./cc/layers/layer.cc.orig	2014-04-24 22:35:51.000000000 +0200
+++ ./cc/layers/layer.cc	2014-04-24 23:23:42.000000000 +0200
@@ -726,13 +726,15 @@
   DCHECK(current_layer);
   DCHECK(current_layer->id() == scroll_clip_layer_id_);
 
-  gfx::Vector2dF max_offset(
+  // (rene) prevent name collission with /usr/include/vm/vm_map.h on FreeBSD
+  // which also defines max_offset
+  gfx::Vector2dF _max_offset(
       scaled_scroll_bounds.width() - current_layer->bounds().width(),
       scaled_scroll_bounds.height() - current_layer->bounds().height());
   // We need the final scroll offset to be in CSS coords.
-  max_offset.Scale(1.f / scale_factor);
-  max_offset.SetToMax(gfx::Vector2dF());
-  return gfx::ToFlooredVector2d(max_offset);
+  _max_offset.Scale(1.f / scale_factor);
+  _max_offset.SetToMax(gfx::Vector2dF());
+  return gfx::ToFlooredVector2d(_max_offset);
 }
 
 void Layer::SetScrollClipLayerId(int clip_layer_id) {
