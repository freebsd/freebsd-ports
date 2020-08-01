--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2020-07-07 21:58:15 UTC
+++ content/gpu/gpu_sandbox_hook_linux.cc
@@ -97,8 +97,9 @@ static const char kLibV4lEncPluginPath[] =
     "/usr/lib/libv4l/plugins/libv4l-encplugin.so";
 #endif
 
-constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL;
 
+#if !defined(OS_BSD)
 void AddV4L2GpuWhitelist(
     std::vector<BrokerFilePermission>* permissions,
     const service_manager::SandboxSeccompBPF::Options& options) {
@@ -339,8 +340,10 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
   AddStandardGpuWhiteList(&permissions);
   return permissions;
 }
+#endif
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxWhitelist()) {
     for (const char* path : kWhitelistedChromecastPaths) {
@@ -355,6 +358,7 @@ void LoadArmGpuLibraries() {
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -394,12 +398,14 @@ void LoadV4L2Libraries(
 }
 
 void LoadChromecastV4L2Libraries() {
+#if !defined(OS_BSD)
   for (const char* path : kWhitelistedChromecastPaths) {
     const std::string library_path(std::string(path) +
                                    std::string("libvpcodec.so"));
     if (dlopen(library_path.c_str(), dlopen_flag))
       break;
   }
+#endif
 }
 
 bool LoadLibrariesForGpu(
@@ -421,6 +427,7 @@ bool LoadLibrariesForGpu(
   return true;
 }
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const service_manager::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
@@ -442,13 +449,17 @@ bool BrokerProcessPreSandboxHook(
   service_manager::SetProcessTitleFromCommandLine(nullptr);
   return true;
 }
+#endif
 
 }  // namespace
 
 bool GpuProcessPreSandboxHook(service_manager::SandboxLinux::Options options) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD)
   service_manager::SandboxLinux::GetInstance()->StartBrokerProcess(
       CommandSetForGPU(options), FilePermissionsForGpu(options),
       base::BindOnce(BrokerProcessPreSandboxHook), options);
+#endif
 
   if (!LoadLibrariesForGpu(options))
     return false;
