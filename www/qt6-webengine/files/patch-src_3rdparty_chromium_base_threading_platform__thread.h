--- src/3rdparty/chromium/base/threading/platform_thread.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread.h
@@ -211,7 +211,7 @@ class BASE_EXPORT PlatformThread {
   // Returns a realtime period provided by `delegate`.
   static TimeDelta GetRealtimePeriod(Delegate* delegate);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Toggles a specific thread's priority at runtime. This can be used to
   // change the priority of a thread in a different process and will fail
   // if the calling process does not have proper permissions. The
