--- components/optimization_guide/core/optimization_guide_util.cc.orig	2023-11-04 07:08:51 UTC
+++ components/optimization_guide/core/optimization_guide_util.cc
@@ -33,7 +33,7 @@ optimization_guide::proto::Platform GetPlatform() {
   return optimization_guide::proto::PLATFORM_CHROMEOS;
 #elif BUILDFLAG(IS_ANDROID)
   return optimization_guide::proto::PLATFORM_ANDROID;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return optimization_guide::proto::PLATFORM_LINUX;
 #else
   return optimization_guide::proto::PLATFORM_UNKNOWN;
