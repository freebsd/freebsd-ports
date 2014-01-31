--- ./lib/atscppapi/src/GzipInflateTransformation.cc.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./lib/atscppapi/src/GzipInflateTransformation.cc	2014-01-27 08:45:49.000000000 +0000
@@ -122,7 +122,7 @@
 void GzipInflateTransformation::handleInputComplete() {
   int64_t bytes_written = setOutputComplete();
   if (state_->bytes_produced_ != bytes_written) {
-    LOG_ERROR("Gzip bytes produced sanity check failed, inflated bytes = %ld != written bytes = %ld", state_->bytes_produced_, bytes_written);
+    LOG_ERROR("Gzip bytes produced sanity check failed, inflated bytes = %lld != written bytes = %lld", state_->bytes_produced_, bytes_written);
   }
 }
 
