--- third_party/partition_alloc/src/partition_alloc/partition_alloc_base/rand_util_posix.cc.orig	1970-01-01 00:00:00 UTC
+++ third_party/partition_alloc/src/partition_alloc/partition_alloc_base/rand_util_posix.cc
@@ -102,6 +102,10 @@ void RandBytes(void* output, size_t output_length) {
   if (getentropy(output, output_length) == 0) {
     return;
   }
+#elif PA_BUILDFLAG(IS_BSD)
+  if (getentropy(output, output_length) == 0) {
+    return;
+  }
 #endif
   // If getrandom(2) above returned with an error and the /dev/urandom fallback
   // took place on Linux/ChromeOS bots, they would fail with a CHECK in
