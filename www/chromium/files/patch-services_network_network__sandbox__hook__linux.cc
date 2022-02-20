--- services/network/network_sandbox_hook_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ services/network/network_sandbox_hook_linux.cc
@@ -32,6 +32,7 @@ std::vector<BrokerFilePermission> GetNetworkFilePermis
 }
 
 bool NetworkPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   instance->StartBrokerProcess(
@@ -39,6 +40,7 @@ bool NetworkPreSandboxHook(sandbox::policy::SandboxLin
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
