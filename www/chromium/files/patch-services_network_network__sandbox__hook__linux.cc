--- services/network/network_sandbox_hook_linux.cc.orig	2023-04-28 17:01:32 UTC
+++ services/network/network_sandbox_hook_linux.cc
@@ -8,11 +8,14 @@
 #include "base/rand_util.h"
 #include "base/system/sys_info.h"
 
+#if !defined(OS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace network {
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet GetNetworkBrokerCommandSet() {
   return MakeBrokerCommandSet({
       sandbox::syscall_broker::COMMAND_ACCESS,
@@ -30,8 +33,10 @@ std::vector<BrokerFilePermission> GetNetworkFilePermis
   // TODO(tsepez): remove universal permission under filesystem root.
   return {BrokerFilePermission::ReadWriteCreateRecursive("/")};
 }
+#endif
 
 bool NetworkPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   instance->StartBrokerProcess(
@@ -39,6 +44,7 @@ bool NetworkPreSandboxHook(sandbox::policy::SandboxLin
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
