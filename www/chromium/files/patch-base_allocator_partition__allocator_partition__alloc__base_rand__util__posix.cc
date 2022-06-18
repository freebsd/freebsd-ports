--- base/allocator/partition_allocator/partition_alloc_base/rand_util_posix.cc.orig	2022-06-17 14:20:10 UTC
+++ base/allocator/partition_allocator/partition_alloc_base/rand_util_posix.cc
@@ -88,6 +88,10 @@ void RandBytes(void* output, size_t output_length) {
       return;
     }
   }
+#elif BUILDFLAG(IS_BSD)
+  if (getentropy(output, output_length) == 0) {
+    return;
+  }
 #endif
 
   // If the OS-specific mechanisms didn't work, fall through to reading from
