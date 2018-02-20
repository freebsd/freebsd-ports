--- third_party/webrtc/system_wrappers/source/timestamp_extrapolator.cc.orig	2017-12-24 19:40:16.381935000 +0100
+++ third_party/webrtc/system_wrappers/source/timestamp_extrapolator.cc	2017-12-24 19:40:27.636036000 +0100
@@ -12,6 +12,8 @@
 
 #include <algorithm>
 
+#undef _P
+
 namespace webrtc {
 
 TimestampExtrapolator::TimestampExtrapolator(int64_t start_ms)
