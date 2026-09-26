--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/rand_util_posix.cc.orig	2026-09-25 15:26:43 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/rand_util_posix.cc
@@ -29,7 +29,7 @@
 
 namespace {
 
-#if !PA_BUILDFLAG(IS_APPLE)
+#if !PA_BUILDFLAG(IS_APPLE) && !PA_BUILDFLAG(IS_BSD)
 
 #if PA_BUILDFLAG(IS_AIX)
 // AIX has no 64-bit support for O_CLOEXEC.
@@ -88,6 +88,8 @@ void RandBytes(void* output, size_t output_length) {
   PA_BASE_CHECK(getentropy(output, output_length) == 0);
 #elif PA_BUILDFLAG(IS_APPLE)
   PA_BASE_CHECK(CCRandomGenerateBytes(output, output_length) == kCCSuccess);
+#elif PA_BUILDFLAG(IS_BSD)
+  PA_BASE_CHECK(getentropy(output, output_length) == 0);
 #else
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
   // Use `syscall(__NR_getrandom...` to avoid a dependency on
