--- ./ppapi/proxy/file_io_resource.cc.orig	2014-08-20 21:02:40.000000000 +0200
+++ ./ppapi/proxy/file_io_resource.cc	2014-08-22 15:06:26.000000000 +0200
@@ -283,15 +283,17 @@
 
   if (check_quota_) {
     int64_t increase = 0;
-    uint64_t max_offset = 0;
+    // (rene) avoid name collission with /usr/include/vm/vm_map.h on FreeBSD
+    // which also defines max_offset
+    uint64_t _max_offset = 0;
     bool append = (open_flags_ & PP_FILEOPENFLAG_APPEND) != 0;
     if (append) {
       increase = bytes_to_write;
     } else {
-      uint64_t max_offset = offset + bytes_to_write;
-      if (max_offset > static_cast<uint64_t>(kint64max))
+      uint64_t _max_offset = offset + bytes_to_write;
+      if (_max_offset > static_cast<uint64_t>(kint64max))
         return PP_ERROR_FAILED;  // amount calculation would overflow.
-      increase = static_cast<int64_t>(max_offset) - max_written_offset_;
+      increase = static_cast<int64_t>(_max_offset) - max_written_offset_;
     }
 
     if (increase > 0) {
@@ -315,7 +317,7 @@
       if (append)
         append_mode_write_amount_ += bytes_to_write;
       else
-        max_written_offset_ = max_offset;
+        max_written_offset_ = _max_offset;
     }
   }
   return WriteValidated(offset, buffer, bytes_to_write, callback);
@@ -593,9 +595,9 @@
   } else {
     DCHECK_LE(offset + bytes_to_write - max_written_offset_, granted);
 
-    int64_t max_offset = offset + bytes_to_write;
-    if (max_written_offset_ < max_offset)
-      max_written_offset_ = max_offset;
+    int64_t _max_offset = offset + bytes_to_write;
+    if (max_written_offset_ < _max_offset)
+      max_written_offset_ = _max_offset;
   }
 
   if (callback->is_blocking()) {
