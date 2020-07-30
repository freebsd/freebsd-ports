--- remoting/host/remoting_me2me_host.cc.orig	2020-07-07 21:58:16 UTC
+++ remoting/host/remoting_me2me_host.cc
@@ -118,13 +118,13 @@
 #include "remoting/host/mac/permission_utils.h"
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 #include "base/linux_util.h"
 #include "remoting/host/audio_capturer_linux.h"
 #include "remoting/host/linux/certificate_watcher.h"
 #include "ui/gfx/x/x11.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include <commctrl.h>
@@ -159,11 +159,11 @@ const char kApplicationName[] = "chromoting";
 const char kStdinConfigPath[] = "-";
 #endif  // !defined(REMOTING_MULTI_PROCESS)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // The command line switch used to pass name of the pipe to capture audio on
 // linux.
 const char kAudioPipeSwitchName[] = "audio-pipe-name";
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
 // The command line switch used to pass name of the unix domain socket used to
@@ -353,7 +353,7 @@ class HostProcess : public ConfigWatcher::Delegate,
 
   std::unique_ptr<ChromotingHostContext> context_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Watch for certificate changes and kill the host when changes occur
   std::unique_ptr<CertificateWatcher> cert_watcher_;
 #endif
@@ -749,7 +749,7 @@ void HostProcess::CreateAuthenticatorFactory() {
     DCHECK(third_party_auth_config_.token_url.is_valid());
     DCHECK(third_party_auth_config_.token_validation_url.is_valid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (!cert_watcher_) {
       cert_watcher_.reset(new CertificateWatcher(
           base::Bind(&HostProcess::ShutdownHost, this, kSuccessExitCode),
@@ -835,7 +835,7 @@ void HostProcess::StartOnUiThread() {
       base::Bind(&HostProcess::OnPolicyUpdate, base::Unretained(this)),
       base::Bind(&HostProcess::OnPolicyError, base::Unretained(this)));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If an audio pipe is specific on the command-line then initialize
   // AudioCapturerLinux to capture from it.
   base::FilePath audio_pipe_name = base::CommandLine::ForCurrentProcess()->
@@ -844,7 +844,7 @@ void HostProcess::StartOnUiThread() {
     remoting::AudioCapturerLinux::InitializePipeReader(
         context_->audio_task_runner(), audio_pipe_name);
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   base::FilePath security_key_socket_name =
@@ -893,7 +893,7 @@ void HostProcess::ShutdownOnUiThread() {
   // It is now safe for the HostProcess to be deleted.
   self_ = nullptr;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio
   // thread will remain in-use and prevent the process from exiting.
   // TODO(wez): DesktopEnvironmentFactory should own the pipe reader.
@@ -1486,7 +1486,7 @@ void HostProcess::StartHost() {
   host_->AddExtension(std::make_unique<TestEchoExtension>());
 
   // TODO(simonmorris): Get the maximum session duration from a policy.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   host_->SetMaximumSessionDuration(base::TimeDelta::FromHours(20));
 #endif
 
@@ -1656,7 +1656,7 @@ void HostProcess::OnCrash(const std::string& function_
 int HostProcessMain() {
   HOST_LOG << "Starting host process: version " << STRINGIZE(VERSION);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!base::CommandLine::ForCurrentProcess()->HasSwitch(
           kReportOfflineReasonSwitchName)) {
     // Required in order for us to run multiple X11 threads.
