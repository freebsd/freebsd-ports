--- src/3rdparty/chromium/media/base/status.cc.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/media/base/status.cc
@@ -66,7 +66,9 @@ Status&& Status::AddCause(Status&& cause) && {
 
 void Status::AddFrame(const base::Location& location) {
   DCHECK(data_);
+#if SUPPORTS_LOCATION_BUILTINS
   data_->frames.push_back(MediaSerialize(location));
+#endif
 }
 
 Status OkStatus() {
