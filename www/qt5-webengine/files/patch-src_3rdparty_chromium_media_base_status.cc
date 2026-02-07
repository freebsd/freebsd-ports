--- src/3rdparty/chromium/media/base/status.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/media/base/status.cc
@@ -70,7 +70,9 @@ void Status::AddFrame(const base::Location& location) 
 
 void Status::AddFrame(const base::Location& location) {
   DCHECK(data_);
+#if SUPPORTS_LOCATION_BUILTINS
   data_->frames.push_back(MediaSerialize(location));
+#endif
 }
 
 Status OkStatus() {
