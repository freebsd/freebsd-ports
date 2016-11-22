--- base/linux_util.cc.orig	2016-08-13 05:03:14.838982000 +0300
+++ base/linux_util.cc	2016-08-13 05:04:48.912092000 +0300
@@ -86,12 +86,14 @@
     "CrOS";
 #elif defined(OS_ANDROID)
     "Android";
+#elif defined(OS_BSD)
+    "BSD";
 #else  // if defined(OS_LINUX)
     "Unknown";
 #endif

 std::string GetLinuxDistro() {
-#if defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   return g_linux_distro;
 #elif defined(OS_LINUX)
   LinuxDistroHelper* distro_state_singleton = LinuxDistroHelper::GetInstance();
