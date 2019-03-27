--- src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc
@@ -14,6 +14,7 @@ using sandbox::syscall_broker::MakeBrokerCommandSet;
 namespace network {
 
 bool NetworkPreSandboxHook(service_manager::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = service_manager::SandboxLinux::GetInstance();
 
   // TODO(tsepez): remove universal permission under filesytem root.
@@ -32,6 +33,7 @@ bool NetworkPreSandboxHook(service_manager::SandboxLin
       service_manager::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandbox(false /* from_zygote */);
+#endif
   return true;
 }
 
