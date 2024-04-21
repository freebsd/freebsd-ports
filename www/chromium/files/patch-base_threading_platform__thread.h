--- base/threading/platform_thread.h.orig	2024-04-19 13:02:56 UTC
+++ base/threading/platform_thread.h
@@ -46,6 +46,8 @@ typedef DWORD PlatformThreadId;
 typedef zx_koid_t PlatformThreadId;
 #elif BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
