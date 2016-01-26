--- cc/layers/scrollbar_layer_impl_base.cc.orig	2016-01-21 13:37:26.739709722 +0100
+++ cc/layers/scrollbar_layer_impl_base.cc	2016-01-21 13:37:43.139708550 +0100
@@ -183,8 +183,8 @@
   int thumb_offset = TrackStart();
   if (maximum > 0) {
     float ratio = clamped_current_pos / maximum;
-    float max_offset = track_length - thumb_length;
-    thumb_offset += static_cast<int>(ratio * max_offset);
+    float _max_offset = track_length - thumb_length;
+    thumb_offset += static_cast<int>(ratio * _max_offset);
   }
 
   float thumb_thickness_adjustment =
