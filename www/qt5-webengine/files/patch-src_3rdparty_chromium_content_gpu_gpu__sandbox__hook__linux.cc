--- src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc
@@ -100,6 +100,7 @@ constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | R
 
 constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
 
+#if !defined(OS_BSD)
 void AddV4L2GpuPermissions(
     std::vector<BrokerFilePermission>* permissions,
     const sandbox::policy::SandboxSeccompBPF::Options& options) {
@@ -359,8 +360,10 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
   AddStandardGpuPermissions(&permissions);
   return permissions;
 }
+#endif
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -375,6 +378,7 @@ void LoadArmGpuLibraries() {
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -414,12 +418,14 @@ void LoadChromecastV4L2Libraries() {
 }
 
 void LoadChromecastV4L2Libraries() {
+#if !defined(OS_BSD)
   for (const char* path : kAllowedChromecastPaths) {
     const std::string library_path(std::string(path) +
                                    std::string("libvpcodec.so"));
     if (dlopen(library_path.c_str(), dlopen_flag))
       break;
   }
+#endif
 }
 
 bool LoadLibrariesForGpu(
@@ -466,9 +472,12 @@ bool GpuProcessPreSandboxHook(sandbox::policy::Sandbox
 }  // namespace
 
 bool GpuProcessPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD)
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       CommandSetForGPU(options), FilePermissionsForGpu(options),
       base::BindOnce(BrokerProcessPreSandboxHook), options);
+#endif
 
   if (!LoadLibrariesForGpu(options))
     return false;
