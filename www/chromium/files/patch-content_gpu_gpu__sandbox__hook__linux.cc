--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2022-07-22 17:30:31 UTC
+++ content/gpu/gpu_sandbox_hook_linux.cc
@@ -114,6 +114,7 @@ void AddStandardChromeOsPermissions(
   permissions->push_back(BrokerFilePermission::ReadOnly(kAngleGlesPath));
 }
 
+#if !defined(OS_BSD)
 void AddV4L2GpuPermissions(
     std::vector<BrokerFilePermission>* permissions,
     const sandbox::policy::SandboxSeccompBPF::Options& options) {
@@ -431,8 +432,10 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
   AddStandardGpuPermissions(&permissions);
   return permissions;
 }
+#endif
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -474,6 +477,7 @@ void LoadArmGpuLibraries() {
         dlopen(driver_paths[i], dlopen_flag);
     }
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -539,12 +543,14 @@ void LoadV4L2Libraries(
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
@@ -571,6 +577,7 @@ bool LoadLibrariesForGpu(
   return true;
 }
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const sandbox::policy::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
@@ -593,13 +600,17 @@ bool BrokerProcessPreSandboxHook(
   SetProcessTitleFromCommandLine(nullptr);
   return true;
 }
+#endif
 
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
