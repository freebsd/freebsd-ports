--- src/3rdparty/chromium/components/performance_manager/public/features.h.orig	2023-11-03 10:09:45 UTC
+++ src/3rdparty/chromium/components/performance_manager/public/features.h
@@ -28,7 +28,7 @@ BASE_DECLARE_FEATURE(kRunOnDedicatedThreadPoolThread);
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
