--- gpu/config/gpu_test_config.cc.orig	2022-02-07 13:39:41 UTC
+++ gpu/config/gpu_test_config.cc
@@ -29,7 +29,7 @@ GPUTestConfig::OS GetCurrentOS() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return GPUTestConfig::kOsChromeOS;
 #elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    defined(OS_OPENBSD)
+    defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32_t major_version = 0;
