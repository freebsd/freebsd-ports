--- src/3rdparty/chromium/components/performance_manager/public/features.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/performance_manager/public/features.h
@@ -17,7 +17,7 @@ namespace performance_manager::features {
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
