--- media/base/status.cc.orig	2020-11-13 06:36:44 UTC
+++ media/base/status.cc
@@ -70,7 +70,9 @@ Status&& Status::AddCause(Status&& cause) && {
 
 void Status::AddFrame(const base::Location& location) {
   DCHECK(data_);
+#if SUPPORTS_LOCATION_BUILTINS
   data_->frames.push_back(MediaSerialize(location));
+#endif
 }
 
 Status OkStatus() {
