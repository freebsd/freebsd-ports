--- src/3rdparty/chromium/gpu/config/gpu_test_config.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_test_config.cc
@@ -29,7 +29,7 @@ GPUTestConfig::OS GetCurrentOS() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return GPUTestConfig::kOsChromeOS;
 #elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_OPENBSD)
+    BUILDFLAG(IS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif BUILDFLAG(IS_WIN)
   int32_t major_version = 0;
