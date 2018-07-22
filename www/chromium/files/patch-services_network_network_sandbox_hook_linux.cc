--- services/network/network_sandbox_hook_linux.cc.orig	2018-07-20 00:26:50.262722000 +0200
+++ services/network/network_sandbox_hook_linux.cc	2018-07-20 00:17:37.945110000 +0200
@@ -14,6 +14,7 @@
 namespace network {
 
 bool NetworkPreSandboxHook(service_manager::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = service_manager::SandboxLinux::GetInstance();
 
   // TODO(tsepez): remove universal permission under filesytem root.
@@ -32,6 +33,7 @@
       service_manager::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandbox(false /* from_zygote */);
+#endif
   return true;
 }
 
