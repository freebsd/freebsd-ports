--- ./lib/atscppapi/src/GzipDeflateTransformation.cc.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./lib/atscppapi/src/GzipDeflateTransformation.cc	2014-01-27 08:45:49.000000000 +0000
@@ -97,20 +97,20 @@
   vector<unsigned char> buffer(buffer_size);
 
   do {
-    LOG_DEBUG("Iteration %d: Deflate will compress %ld bytes", ++iteration, data.size());
+    LOG_DEBUG("Iteration %d: Deflate will compress %zu bytes", ++iteration, data.size());
     state_->z_stream_.avail_out = buffer_size;
     state_->z_stream_.next_out = &buffer[0];
 
     int err = deflate(&state_->z_stream_, Z_SYNC_FLUSH);
     if (Z_OK != err) {
-      LOG_ERROR("Iteration %d: Deflate failed to compress %ld bytes with error code '%d'", iteration, data.size(), err);
+      LOG_ERROR("Iteration %d: Deflate failed to compress %zu bytes with error code '%d'", iteration, data.size(), err);
       return;
     }
 
     int bytes_to_write = buffer_size - state_->z_stream_.avail_out;
     state_->bytes_produced_ += bytes_to_write;
 
-    LOG_DEBUG("Iteration %d: Deflate compressed %ld bytes to %d bytes, producing output...", iteration, data.size(), bytes_to_write);
+    LOG_DEBUG("Iteration %d: Deflate compressed %zu bytes to %d bytes, producing output...", iteration, data.size(), bytes_to_write);
     produce(string(reinterpret_cast<char *>(&buffer[0]), static_cast<size_t>(bytes_to_write)));
   } while (state_->z_stream_.avail_out == 0);
 
@@ -148,7 +148,7 @@
 
   int64_t bytes_written = setOutputComplete();
   if (state_->bytes_produced_ != bytes_written) {
-    LOG_ERROR("Gzip bytes produced sanity check failed, deflated bytes = %ld != written bytes = %ld", state_->bytes_produced_, bytes_written);
+    LOG_ERROR("Gzip bytes produced sanity check failed, deflated bytes = %lld != written bytes = %lld", state_->bytes_produced_, bytes_written);
   }
 }
 
