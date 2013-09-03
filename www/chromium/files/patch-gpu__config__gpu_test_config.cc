--- gpu/config/gpu_test_config.cc.orig	2013-09-02 21:22:26.000000000 +0300
+++ gpu/config/gpu_test_config.cc	2013-09-02 21:23:55.000000000 +0300
@@ -17,8 +17,6 @@
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
-  return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32 major_version = 0;
   int32 minor_version = 0;
@@ -53,6 +51,8 @@
   }
 #elif defined(OS_ANDROID)
   return GPUTestConfig::kOsAndroid;
+#elif defined(OS_POSIX)
+  return GPUTestConfig::kOsLinux;
 #endif
   return GPUTestConfig::kOsUnknown;
 }
