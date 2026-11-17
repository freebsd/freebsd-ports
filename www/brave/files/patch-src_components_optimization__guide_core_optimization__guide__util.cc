--- src/components/optimization_guide/core/optimization_guide_util.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/optimization_guide/core/optimization_guide_util.cc
@@ -38,7 +38,7 @@ optimization_guide::proto::Platform GetP
   return optimization_guide::proto::PLATFORM_CHROMEOS;
 #elif BUILDFLAG(IS_ANDROID)
   return optimization_guide::proto::PLATFORM_ANDROID;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return optimization_guide::proto::PLATFORM_LINUX;
 #else
   return optimization_guide::proto::PLATFORM_UNDEFINED;
@@ -198,7 +198,7 @@ optimization_guide::proto::ChromePlatfor
   return optimization_guide::proto::CHROME_PLATFORM_CHROMEOS;
 #elif BUILDFLAG(IS_ANDROID)
   return optimization_guide::proto::CHROME_PLATFORM_ANDROID;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return optimization_guide::proto::CHROME_PLATFORM_LINUX;
 #else
   return optimization_guide::proto::CHROME_PLATFORM_UNKNOWN;
