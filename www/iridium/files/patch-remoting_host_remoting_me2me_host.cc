--- remoting/host/remoting_me2me_host.cc.orig	2018-03-20 23:05:29.000000000 +0100
+++ remoting/host/remoting_me2me_host.cc	2018-03-24 18:19:49.996963000 +0100
@@ -115,13 +115,13 @@
 #include "base/mac/scoped_cftyperef.h"
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
@@ -156,11 +156,11 @@
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
@@ -351,7 +351,7 @@
 
   std::unique_ptr<ChromotingHostContext> context_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Watch for certificate changes and kill the host when changes occur
   std::unique_ptr<CertificateWatcher> cert_watcher_;
 #endif
@@ -565,10 +565,10 @@
   enable_window_capture_ = cmd_line->HasSwitch(kWindowIdSwitchName);
   if (enable_window_capture_) {
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     LOG(WARNING) << "Window capturing is not fully supported on Linux or "
                     "Windows.";
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
     // uint32_t is large enough to hold window IDs on all platforms.
     uint32_t window_id;
@@ -761,7 +761,7 @@
     DCHECK(third_party_auth_config_.token_url.is_valid());
     DCHECK(third_party_auth_config_.token_validation_url.is_valid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (!cert_watcher_) {
       cert_watcher_.reset(new CertificateWatcher(
           base::Bind(&HostProcess::ShutdownHost, this, kSuccessExitCode),
@@ -847,7 +847,7 @@
       base::Bind(&HostProcess::OnPolicyUpdate, base::Unretained(this)),
       base::Bind(&HostProcess::OnPolicyError, base::Unretained(this)));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If an audio pipe is specific on the command-line then initialize
   // AudioCapturerLinux to capture from it.
   base::FilePath audio_pipe_name = base::CommandLine::ForCurrentProcess()->
@@ -856,7 +856,7 @@
     remoting::AudioCapturerLinux::InitializePipeReader(
         context_->audio_task_runner(), audio_pipe_name);
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   base::FilePath security_key_socket_name =
@@ -914,7 +914,7 @@
   // It is now safe for the HostProcess to be deleted.
   self_ = nullptr;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio
   // thread will remain in-use and prevent the process from exiting.
   // TODO(wez): DesktopEnvironmentFactory should own the pipe reader.
@@ -1546,7 +1546,7 @@
   host_->AddExtension(std::make_unique<TestEchoExtension>());
 
   // TODO(simonmorris): Get the maximum session duration from a policy.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   host_->SetMaximumSessionDuration(base::TimeDelta::FromHours(20));
 #endif
 
@@ -1705,7 +1705,7 @@
 int HostProcessMain() {
   HOST_LOG << "Starting host process: version " << STRINGIZE(VERSION);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!base::CommandLine::ForCurrentProcess()->HasSwitch(
           kReportOfflineReasonSwitchName)) {
     // Required in order for us to run multiple X11 threads.
