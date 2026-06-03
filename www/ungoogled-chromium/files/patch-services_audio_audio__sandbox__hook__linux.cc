--- services/audio/audio_sandbox_hook_linux.cc.orig	2026-01-16 13:40:34 UTC
+++ services/audio/audio_sandbox_hook_linux.cc
@@ -146,6 +146,7 @@ void AddPulseAudioFilePermissions(
 }
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 std::vector<BrokerFilePermission> GetAudioFilePermissions() {
   std::vector<BrokerFilePermission> permissions{
       BrokerFilePermission::ReadOnly("/dev/urandom"),
@@ -174,10 +175,12 @@ void LoadAudioLibraries() {
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
   // TODO(crbug.com/40579955) enable namespace sandbox. Currently, if
   // enabled, connect() on pulse native socket fails with ENOENT (called from
   // pa_context_connect).
+#endif
 
   return true;
 }
