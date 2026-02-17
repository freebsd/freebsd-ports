--- components/on_device_translation/service/sandbox_hook.cc.orig	2026-02-16 10:45:29 UTC
+++ components/on_device_translation/service/sandbox_hook.cc
@@ -7,12 +7,15 @@
 #include "components/on_device_translation/service/translate_kit_client.h"
 #include "sandbox/linux/syscall_broker/broker_command.h"
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace on_device_translation {
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 // Gets the file permissions required by the TranslateKit
 std::vector<BrokerFilePermission> GetOnDeviceTranslationFilePermissions() {
   std::vector<BrokerFilePermission> permissions{
@@ -21,6 +24,7 @@ std::vector<BrokerFilePermission> GetOnDeviceTranslati
   };
   return permissions;
 }
+#endif
 
 }  // namespace
 
@@ -29,6 +33,7 @@ bool OnDeviceTranslationSandboxHook(
   // Call `TranslateKitClient::Get()` to load libtranslatekit.so
   TranslateKitClient::Get();
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(MakeBrokerCommandSet({
                                    sandbox::syscall_broker::COMMAND_OPEN,
@@ -36,6 +41,7 @@ bool OnDeviceTranslationSandboxHook(
                                GetOnDeviceTranslationFilePermissions(),
                                options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
