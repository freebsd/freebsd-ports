--- src/3rdparty/chromium/gpu/config/gpu_test_config.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_test_config.cc
@@ -27,7 +27,7 @@ GPUTestConfig::OS GetCurrentOS() {
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32_t major_version = 0;
