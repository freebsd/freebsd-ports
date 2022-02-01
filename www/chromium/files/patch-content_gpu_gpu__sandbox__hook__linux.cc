--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2021-12-31 00:57:32 UTC
+++ content/gpu/gpu_sandbox_hook_linux.cc
@@ -89,6 +89,12 @@ static const char kLibTegraPath[] = "/usr/lib64/libteg
 static const char kLibV4l2Path[] = "/usr/lib64/libv4l2.so";
 static const char kLibV4lEncPluginPath[] =
     "/usr/lib64/libv4l/plugins/libv4l-encplugin.so";
+#elif defined(OS_BSD)
+static const char kLibGlesPath[] = "/usr/local/lib/libGLESv2.so.2";
+static const char kLibEglPath[] = "/usr/local/lib/libEGL.so.1";
+static const char kLibV4l2Path[] = "/usr/local/lib/libv4l2.so";
+static const char kLibV4lEncPluginPath[] =
+    "/usr/local/lib/libv4l/plugins/libv4l-encplugin.so";
 #else
 static const char kLibGlesPath[] = "/usr/lib/libGLESv2.so.2";
 static const char kLibEglPath[] = "/usr/lib/libEGL.so.1";
@@ -401,6 +407,7 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
 }
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -433,6 +440,7 @@ void LoadArmGpuLibraries() {
         dlopen(driver_paths[i], dlopen_flag);
     }
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
