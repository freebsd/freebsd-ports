--- base/threading/platform_thread_metrics.h.orig	2025-10-21 16:57:35 UTC
+++ base/threading/platform_thread_metrics.h
@@ -67,7 +67,7 @@ class BASE_EXPORT PlatformThreadMetrics {
       PlatformThreadHandle handle);
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
   static std::unique_ptr<PlatformThreadMetrics> CreateFromId(
       PlatformThreadId tid);
@@ -109,7 +109,7 @@ class BASE_EXPORT PlatformThreadMetrics {
 
   PlatformThreadHandle handle_;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   explicit PlatformThreadMetrics(PlatformThreadId tid) : tid_(tid) {}
 
   PlatformThreadId tid_;
