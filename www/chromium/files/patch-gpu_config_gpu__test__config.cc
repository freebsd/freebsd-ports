--- gpu/config/gpu_test_config.cc.orig	2017-06-05 19:03:08 UTC
+++ gpu/config/gpu_test_config.cc
@@ -24,7 +24,7 @@ namespace {
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32_t major_version = 0;
@@ -255,6 +255,10 @@ bool GPUTestBotConfig::LoadCurrentConfig(const GPUInfo
   bool rt;
   if (gpu_info == NULL) {
     GPUInfo my_gpu_info;
+#if defined(OS_FREEBSD)
+    rt = false;
+    LOG(WARNING) << "CollectGpuID not present on FreeBSD";
+#else
     CollectInfoResult result = CollectBasicGraphicsInfo(&my_gpu_info);
     if (result != kCollectInfoSuccess) {
       LOG(ERROR) << "Fail to identify GPU";
@@ -263,6 +267,7 @@ bool GPUTestBotConfig::LoadCurrentConfig(const GPUInfo
     } else {
       rt = SetGPUInfo(my_gpu_info);
     }
+#endif
   } else {
     rt = SetGPUInfo(*gpu_info);
   }
