--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_base/rand_util_posix.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_base/rand_util_posix.cc
@@ -86,6 +86,10 @@ void RandBytes(void* output, size_t output_length) {
   if (getentropy(output, output_length) == 0) {
     return;
   }
+#elif BUILDFLAG(IS_BSD)
+  if (getentropy(output, output_length) == 0) {
+    return;
+  }
 #endif
 
   // If the OS-specific mechanisms didn't work, fall through to reading from
