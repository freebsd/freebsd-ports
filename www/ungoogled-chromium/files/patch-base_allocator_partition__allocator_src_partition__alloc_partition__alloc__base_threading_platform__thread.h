--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h.orig	2024-02-25 20:22:18 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h
@@ -37,6 +37,8 @@ typedef DWORD PlatformThreadId;
 typedef zx_handle_t PlatformThreadId;
 #elif BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
