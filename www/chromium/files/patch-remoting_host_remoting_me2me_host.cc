--- remoting/host/remoting_me2me_host.cc.orig	2017-12-15 02:04:23.000000000 +0100
+++ remoting/host/remoting_me2me_host.cc	2017-12-24 17:46:36.226255000 +0100
@@ -116,14 +116,14 @@
 #include "base/mac/scoped_cftyperef.h"
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 #include <X11/Xlib.h>
 #undef Status  // Xlib.h #defines this, which breaks protobuf headers.
 #include <base/linux_util.h>
 #include "remoting/host/audio_capturer_linux.h"
 #include "remoting/host/linux/certificate_watcher.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include <commctrl.h>
@@ -158,11 +158,11 @@
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
@@ -353,7 +353,7 @@
 
   std::unique_ptr<ChromotingHostContext> context_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Watch for certificate changes and kill the host when changes occur
   std::unique_ptr<CertificateWatcher> cert_watcher_;
 #endif
@@ -566,10 +566,10 @@
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
@@ -762,7 +762,7 @@
     DCHECK(third_party_auth_config_.token_url.is_valid());
     DCHECK(third_party_auth_config_.token_validation_url.is_valid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (!cert_watcher_) {
       cert_watcher_.reset(new CertificateWatcher(
           base::Bind(&HostProcess::ShutdownHost, this, kSuccessExitCode),
@@ -848,7 +848,7 @@
       base::Bind(&HostProcess::OnPolicyUpdate, base::Unretained(this)),
       base::Bind(&HostProcess::OnPolicyError, base::Unretained(this)));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If an audio pipe is specific on the command-line then initialize
   // AudioCapturerLinux to capture from it.
   base::FilePath audio_pipe_name = base::CommandLine::ForCurrentProcess()->
@@ -857,7 +857,7 @@
     remoting::AudioCapturerLinux::InitializePipeReader(
         context_->audio_task_runner(), audio_pipe_name);
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   base::FilePath security_key_socket_name =
@@ -915,7 +915,7 @@
   // It is now safe for the HostProcess to be deleted.
   self_ = nullptr;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio
   // thread will remain in-use and prevent the process from exiting.
   // TODO(wez): DesktopEnvironmentFactory should own the pipe reader.
@@ -1547,7 +1547,7 @@
   host_->AddExtension(base::MakeUnique<TestEchoExtension>());
 
   // TODO(simonmorris): Get the maximum session duration from a policy.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   host_->SetMaximumSessionDuration(base::TimeDelta::FromHours(20));
 #endif
 
@@ -1706,7 +1706,7 @@
 int HostProcessMain() {
   HOST_LOG << "Starting host process: version " << STRINGIZE(VERSION);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!base::CommandLine::ForCurrentProcess()->HasSwitch(
           kReportOfflineReasonSwitchName)) {
     // Required in order for us to run multiple X11 threads.
