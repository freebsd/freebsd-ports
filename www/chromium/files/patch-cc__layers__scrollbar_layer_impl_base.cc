--- cc/layers/scrollbar_layer_impl_base.cc.orig	2015-05-21 08:37:56.037399000 -0400
+++ cc/layers/scrollbar_layer_impl_base.cc	2015-05-21 08:38:18.153818000 -0400
@@ -226,8 +226,8 @@
   int thumb_offset = TrackStart();
   if (maximum_ > 0) {
     float ratio = clamped_current_pos / maximum_;
-    float max_offset = track_length - thumb_length;
-    thumb_offset += static_cast<int>(ratio * max_offset);
+    float max_offset_ = track_length - thumb_length;
+    thumb_offset += static_cast<int>(ratio * max_offset_);
   }
 
   float thumb_thickness_adjustment =
