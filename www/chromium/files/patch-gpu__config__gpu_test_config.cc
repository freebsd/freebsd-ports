--- gpu/config/gpu_test_config.cc.orig	2014-10-02 17:39:47 UTC
+++ gpu/config/gpu_test_config.cc
@@ -23,8 +23,6 @@
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
-  return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32 major_version = 0;
   int32 minor_version = 0;
@@ -61,6 +59,8 @@
   }
 #elif defined(OS_ANDROID)
   return GPUTestConfig::kOsAndroid;
+#elif defined(OS_POSIX)
+  return GPUTestConfig::kOsLinux;
 #endif
   return GPUTestConfig::kOsUnknown;
 }
@@ -234,6 +234,10 @@
   if (gpu_info == NULL) {
     GPUInfo my_gpu_info;
     GpuIDResult result;
+#if defined(OS_FREEBSD)
+    rt = false;
+    LOG(WARNING) << "CollectGpuID not present on FreeBSD";
+#else
     result = CollectGpuID(&my_gpu_info.gpu.vendor_id,
                           &my_gpu_info.gpu.device_id);
     if (result == kGpuIDNotSupported) {
@@ -243,6 +247,7 @@
     } else {
       rt = SetGPUInfo(my_gpu_info);
     }
+#endif
   } else {
     rt = SetGPUInfo(*gpu_info);
   }
