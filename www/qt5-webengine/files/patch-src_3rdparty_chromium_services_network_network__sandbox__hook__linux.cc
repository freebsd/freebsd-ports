--- src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc
@@ -14,6 +14,7 @@ bool NetworkPreSandboxHook(sandbox::policy::SandboxLin
 namespace network {
 
 bool NetworkPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   // TODO(tsepez): remove universal permission under filesytem root.
@@ -32,6 +33,7 @@ bool NetworkPreSandboxHook(sandbox::policy::SandboxLin
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif // defined(OS_BSD)
   return true;
 }
 
