--- content/utility/speech/speech_recognition_sandbox_hook_linux.cc.orig	2026-11-17 11:49:09 UTC
+++ content/utility/speech/speech_recognition_sandbox_hook_linux.cc
@@ -12,11 +12,14 @@
 #include "sandbox/linux/syscall_broker/broker_command.h"
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace speech {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 // Gets the file permissions required by the Speech On-Device API (SODA).
@@ -53,6 +56,7 @@ std::vector<BrokerFilePermission> GetSodaFilePermissio
 }
 
 }  // namespace
+#endif
 
 const char* GetSodaBinaryPathSwitch() {
   return kSodaBinaryPathSwitch;
@@ -61,6 +65,7 @@ const char* GetSodaBinaryPathSwitch() {
 bool SpeechRecognitionPreSandboxHook(
     base::FilePath binary_path,
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_SODA_INTEGRATION_TESTS)
   base::FilePath test_binary_path = GetSodaTestBinaryPath();
   DCHECK(base::PathExists(test_binary_path));
@@ -88,6 +93,7 @@ bool SpeechRecognitionPreSandboxHook(
                                }),
                                GetSodaFilePermissions(), options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
