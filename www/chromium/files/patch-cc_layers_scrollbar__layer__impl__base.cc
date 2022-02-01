--- cc/layers/scrollbar_layer_impl_base.cc.orig	2021-12-14 11:44:55 UTC
+++ cc/layers/scrollbar_layer_impl_base.cc
@@ -223,8 +223,8 @@ gfx::Rect ScrollbarLayerImplBase::ComputeThumbQuadRect
   int thumb_offset = TrackStart();
   if (maximum > 0) {
     float ratio = clamped_current_pos / maximum;
-    float max_offset = track_length - thumb_length;
-    thumb_offset += static_cast<int>(ratio * max_offset);
+    float _max_offset = track_length - thumb_length;
+    thumb_offset += static_cast<int>(ratio * _max_offset);
   }
 
   float thumb_thickness_adjustment =
