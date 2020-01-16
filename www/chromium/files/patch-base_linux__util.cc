--- base/linux_util.cc.orig	2019-12-16 21:50:40 UTC
+++ base/linux_util.cc
@@ -144,6 +144,8 @@ char g_linux_distro[kDistroSize] =
     "CrOS";
 #elif defined(OS_ANDROID)
     "Android";
+#elif defined(OS_BSD)
+    "BSD";
 #else  // if defined(OS_LINUX)
     "Unknown";
 #endif
@@ -164,7 +166,7 @@ BASE_EXPORT std::string GetKeyValueFromOSReleaseFileFo
 }
 
 std::string GetLinuxDistro() {
-#if defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   return g_linux_distro;
 #elif defined(OS_LINUX)
   LinuxDistroHelper* distro_state_singleton = LinuxDistroHelper::GetInstance();
