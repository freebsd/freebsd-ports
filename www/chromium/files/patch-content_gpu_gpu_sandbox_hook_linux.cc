--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2018-12-12 22:56:07.000000000 +0100
+++ content/gpu/gpu_sandbox_hook_linux.cc	2019-01-11 16:30:27.925996000 +0100
@@ -95,8 +95,9 @@
     "/usr/lib/libv4l/plugins/libv4l-encplugin.so";
 #endif

-constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL;

+#if !defined(OS_BSD)
 void AddV4L2GpuWhitelist(
     std::vector<BrokerFilePermission>* permissions,
     const service_manager::SandboxSeccompBPF::Options& options) {
@@ -265,8 +266,10 @@
   AddStandardGpuWhiteList(&permissions);
   return permissions;
 }
+#endif

 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxWhitelist()) {
     for (const char* path : kWhitelistedChromecastPaths) {
@@ -281,6 +284,7 @@
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }

 bool LoadAmdGpuLibraries() {
@@ -336,6 +340,7 @@
   return true;
 }

+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const service_manager::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
@@ -356,13 +361,17 @@
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
