--- remoting/host/remoting_me2me_host.cc.orig	2021-04-14 18:41:08 UTC
+++ remoting/host/remoting_me2me_host.cc
@@ -120,14 +120,14 @@
 #include "remoting/host/mac/permission_utils.h"
 #endif  // defined(OS_APPLE)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
 #include "remoting/host/audio_capturer_linux.h"
 #include "remoting/host/linux/certificate_watcher.h"
 #include "ui/events/platform/x11/x11_event_source.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include <commctrl.h>
@@ -162,11 +162,11 @@ const char kApplicationName[] = "chromoting";
 const char kStdinConfigPath[] = "-";
 #endif  // !defined(REMOTING_MULTI_PROCESS)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The command line switch used to pass name of the pipe to capture audio on
 // linux.
 const char kAudioPipeSwitchName[] = "audio-pipe-name";
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
 // The command line switch used to pass name of the unix domain socket used to
@@ -359,7 +359,7 @@ class HostProcess : public ConfigWatcher::Delegate,
 
   std::unique_ptr<ChromotingHostContext> context_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Watch for certificate changes and kill the host when changes occur
   std::unique_ptr<CertificateWatcher> cert_watcher_;
 #endif
@@ -772,7 +772,7 @@ void HostProcess::CreateAuthenticatorFactory() {
     DCHECK(third_party_auth_config_.token_url.is_valid());
     DCHECK(third_party_auth_config_.token_validation_url.is_valid());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     if (!cert_watcher_) {
       cert_watcher_ = std::make_unique<CertificateWatcher>(
           base::BindRepeating(&HostProcess::ShutdownHost, this,
@@ -861,7 +861,7 @@ void HostProcess::StartOnUiThread() {
       base::BindRepeating(&HostProcess::OnPolicyUpdate, base::Unretained(this)),
       base::BindRepeating(&HostProcess::OnPolicyError, base::Unretained(this)));
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // If an audio pipe is specific on the command-line then initialize
   // AudioCapturerLinux to capture from it.
   base::FilePath audio_pipe_name = base::CommandLine::ForCurrentProcess()->
@@ -870,7 +870,7 @@ void HostProcess::StartOnUiThread() {
     remoting::AudioCapturerLinux::InitializePipeReader(
         context_->audio_task_runner(), audio_pipe_name);
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   base::FilePath security_key_socket_name =
@@ -919,7 +919,7 @@ void HostProcess::ShutdownOnUiThread() {
   // It is now safe for the HostProcess to be deleted.
   self_ = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio
   // thread will remain in-use and prevent the process from exiting.
   // TODO(wez): DesktopEnvironmentFactory should own the pipe reader.
@@ -1763,7 +1763,7 @@ void HostProcess::OnCrash(const std::string& function_
 int HostProcessMain() {
   HOST_LOG << "Starting host process: version " << STRINGIZE(VERSION);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   std::unique_ptr<ui::X11EventSource> event_source;
   if (!base::CommandLine::ForCurrentProcess()->HasSwitch(
           kReportOfflineReasonSwitchName)) {
