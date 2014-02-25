--- content/browser/renderer_host/pepper/pepper_file_io_host.cc.orig	2014-02-20 21:28:22.000000000 +0100
+++ content/browser/renderer_host/pepper/pepper_file_io_host.cc	2014-02-24 22:13:44.000000000 +0100
@@ -308,10 +308,12 @@
     int64_t actual_offset =
         (open_flags_ & PP_FILEOPENFLAG_APPEND) ? max_written_offset_ : offset;
 
-    uint64_t max_offset = actual_offset + buffer.size();
-    if (max_offset > static_cast<uint64_t>(std::numeric_limits<int64_t>::max()))
-      return PP_ERROR_FAILED;  // max_offset overflows.
-    int64_t amount = static_cast<int64_t>(max_offset) - max_written_offset_;
+    // (rene) rename 'max_offset' to '_max_offset' to avoid a conflict with
+    // /usr/include/vm/vm_map.h on FreeBSD 10.0
+    uint64_t _max_offset = actual_offset + buffer.size();
+    if (_max_offset > static_cast<uint64_t>(std::numeric_limits<int64_t>::max()))
+      return PP_ERROR_FAILED;  // _max_offset overflows.
+    int64_t amount = static_cast<int64_t>(_max_offset) - max_written_offset_;
 
     // Quota request amounts are restricted to 32 bits so we can use atomics
     // when we move this code to the plugin side of the proxy.
