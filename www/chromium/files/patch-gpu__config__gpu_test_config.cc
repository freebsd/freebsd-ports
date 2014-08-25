--- ./gpu/config/gpu_test_config.cc.orig	2014-08-20 21:02:37.000000000 +0200
+++ ./gpu/config/gpu_test_config.cc	2014-08-22 15:06:26.000000000 +0200
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
