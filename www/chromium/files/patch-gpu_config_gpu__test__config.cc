--- gpu/config/gpu_test_config.cc.orig	2021-04-14 18:41:04 UTC
+++ gpu/config/gpu_test_config.cc
@@ -28,7 +28,7 @@ namespace {
 GPUTestConfig::OS GetCurrentOS() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return GPUTestConfig::kOsChromeOS;
-#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_OPENBSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
