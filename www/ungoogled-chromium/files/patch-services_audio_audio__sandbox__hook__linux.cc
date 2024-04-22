--- services/audio/audio_sandbox_hook_linux.cc.orig	2024-02-03 15:42:55 UTC
+++ services/audio/audio_sandbox_hook_linux.cc
@@ -144,6 +144,7 @@ void AddPulseAudioFilePermissions(
 }
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 std::vector<BrokerFilePermission> GetAudioFilePermissions() {
   std::vector<BrokerFilePermission> permissions{
       BrokerFilePermission::ReadOnly("/dev/urandom"),
@@ -172,10 +173,12 @@ void LoadAudioLibraries() {
     }
   }
 }
+#endif
 
 }  // namespace
 
 bool AudioPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   LoadAudioLibraries();
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(MakeBrokerCommandSet({
@@ -195,6 +198,7 @@ bool AudioPreSandboxHook(sandbox::policy::SandboxLinux
   // TODO(https://crbug.com/850878) enable namespace sandbox. Currently, if
   // enabled, connect() on pulse native socket fails with ENOENT (called from
   // pa_context_connect).
+#endif
 
   return true;
 }
