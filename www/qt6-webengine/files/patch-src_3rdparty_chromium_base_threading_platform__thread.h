--- src/3rdparty/chromium/base/threading/platform_thread.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread.h
@@ -48,6 +48,8 @@ typedef mach_port_t PlatformThreadId;
 typedef zx_koid_t PlatformThreadId;
 #elif BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
