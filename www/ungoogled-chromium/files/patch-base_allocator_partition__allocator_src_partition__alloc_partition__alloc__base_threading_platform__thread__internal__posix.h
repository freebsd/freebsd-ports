--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_internal_posix.h.orig	2025-09-10 13:22:16 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_internal_posix.h
@@ -15,7 +15,7 @@
 
 namespace partition_alloc::internal::base::internal {
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 // Current thread id is cached in thread local storage for performance reasons.
 // In some rare cases it's important to invalidate that cache explicitly (e.g.
 // after going through clone() syscall which does not call pthread_atfork()
