--- components/performance_manager/public/features.h.orig	2023-11-22 14:00:11 UTC
+++ components/performance_manager/public/features.h
@@ -28,7 +28,7 @@ BASE_DECLARE_FEATURE(kRunOnDedicatedThreadPoolThread);
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
