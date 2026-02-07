--- base/threading/platform_thread_metrics.cc.orig	2026-01-16 13:40:34 UTC
+++ base/threading/platform_thread_metrics.cc
@@ -54,7 +54,7 @@ PlatformThreadMetrics::CreateForCurrentThread() {
 }
 
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<PlatformThreadMetrics>
