--- content/services/isolated_xr_device/xr_sandbox_hook_linux.cc.orig	2026-10-18 13:29:39 UTC
+++ content/services/isolated_xr_device/xr_sandbox_hook_linux.cc
@@ -435,6 +435,7 @@ bool XrPreSandboxHook(sandbox::policy::SandboxLinux::O
       manifest ? GetRuntimeLibraryPath(manifest_path, manifest->library_path)
                : std::string();
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(
       MakeBrokerCommandSet({
@@ -449,6 +450,7 @@ bool XrPreSandboxHook(sandbox::policy::SandboxLinux::O
           manifest_path, runtime_library_path,
           manifest ? manifest->runtime_id : XrRuntimeId::kOther),
       options);
+#endif
 
   // Pre-warm the runtime + graphics driver closure now that the broker has
   // forked, so the recursive system-library grants are unnecessary.
