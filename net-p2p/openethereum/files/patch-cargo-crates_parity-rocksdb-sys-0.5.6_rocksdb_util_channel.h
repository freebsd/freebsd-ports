--- cargo-crates/parity-rocksdb-sys-0.5.6/rocksdb/util/channel.h.orig	2020-11-20 16:25:54 UTC
+++ cargo-crates/parity-rocksdb-sys-0.5.6/rocksdb/util/channel.h
@@ -31,7 +31,7 @@ class channel {
     return buffer_.empty() && eof_;
   }
 
-  size_t size() const {
+  size_t size() {
     std::lock_guard<std::mutex> lk(lock_);
     return buffer_.size();
   }
