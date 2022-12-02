--- components/performance_manager/public/features.h.orig	2022-12-02 17:56:32 UTC
+++ components/performance_manager/public/features.h
@@ -20,7 +20,7 @@ BASE_DECLARE_FEATURE(kRunOnMainThread);
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
