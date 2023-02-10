--- src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc
@@ -26,12 +26,15 @@ sandbox::syscall_broker::BrokerCommandSet GetNetworkBr
   });
 }
 
+#if !defined(OS_BSD)
 std::vector<BrokerFilePermission> GetNetworkFilePermissions() {
   // TODO(tsepez): remove universal permission under filesystem root.
   return {BrokerFilePermission::ReadWriteCreateRecursive("/")};
 }
+#endif
 
 bool NetworkPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   instance->StartBrokerProcess(
@@ -39,6 +42,7 @@ bool NetworkPreSandboxHook(sandbox::policy::SandboxLin
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
