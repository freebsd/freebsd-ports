--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h.orig	2026-01-16 14:21:21 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h
@@ -38,6 +38,8 @@ typedef DWORD PlatformThreadId;
 typedef zx_handle_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif PA_BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
