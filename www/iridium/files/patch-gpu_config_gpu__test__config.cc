--- gpu/config/gpu_test_config.cc.orig	2018-03-20 23:05:26.000000000 +0100
+++ gpu/config/gpu_test_config.cc	2018-03-26 13:47:37.264475000 +0200
@@ -24,7 +24,7 @@
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32_t major_version = 0;
