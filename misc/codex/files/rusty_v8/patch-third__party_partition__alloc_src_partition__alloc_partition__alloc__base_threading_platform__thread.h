--- third_party/partition_alloc/src/partition_alloc/partition_alloc_base/threading/platform_thread.h.orig	1970-01-01 00:00:00 UTC
+++ third_party/partition_alloc/src/partition_alloc/partition_alloc_base/threading/platform_thread.h
@@ -38,6 +38,8 @@ typedef mach_port_t PlatformThreadId;
 typedef zx_handle_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif PA_BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
