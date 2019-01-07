--- services/network/network_sandbox_hook_linux.cc.orig	2018-12-03 21:17:09.000000000 +0100
+++ services/network/network_sandbox_hook_linux.cc	2018-12-14 00:53:22.847706000 +0100
@@ -14,6 +14,7 @@
 namespace network {
 
 bool NetworkPreSandboxHook(service_manager::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = service_manager::SandboxLinux::GetInstance();
 
   // TODO(tsepez): remove universal permission under filesytem root.
@@ -32,6 +33,7 @@
       service_manager::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif // defined(OS_BSD)
   return true;
 }
 
