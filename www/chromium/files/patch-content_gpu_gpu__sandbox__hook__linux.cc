--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2020-11-19 08:18:33 UTC
+++ content/gpu/gpu_sandbox_hook_linux.cc
@@ -361,6 +361,7 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
 }
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -375,6 +376,7 @@ void LoadArmGpuLibraries() {
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
