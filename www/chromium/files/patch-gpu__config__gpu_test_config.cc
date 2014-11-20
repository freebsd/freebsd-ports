--- gpu/config/gpu_test_config.cc.orig	2014-10-10 08:54:15 UTC
+++ gpu/config/gpu_test_config.cc
@@ -23,7 +23,7 @@
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32 major_version = 0;
@@ -233,6 +233,10 @@
   bool rt;
   if (gpu_info == NULL) {
     GPUInfo my_gpu_info;
+#if defined(OS_FREEBSD)
+    rt = false;
+    LOG(WARNING) << "CollectGpuID not present on FreeBSD";
+#else
     CollectInfoResult result = CollectGpuID(
         &my_gpu_info.gpu.vendor_id, &my_gpu_info.gpu.device_id);
     if (result != kCollectInfoSuccess) {
@@ -242,6 +246,7 @@
     } else {
       rt = SetGPUInfo(my_gpu_info);
     }
+#endif
   } else {
     rt = SetGPUInfo(*gpu_info);
   }
