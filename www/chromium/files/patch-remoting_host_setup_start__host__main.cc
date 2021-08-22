--- remoting/host/setup/start_host_main.cc.orig	2021-07-28 08:19:29 UTC
+++ remoting/host/setup/start_host_main.cc
@@ -32,10 +32,10 @@
 #include <unistd.h>
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "remoting/host/setup/daemon_controller_delegate_linux.h"
 #include "remoting/host/setup/start_host_as_root.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "base/process/process_info.h"
@@ -124,12 +124,12 @@ void OnDone(HostStarter::Result result) {
 }  // namespace
 
 int StartHostMain(int argc, char** argv) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Minimize the amount of code that runs as root on Posix systems.
   if (getuid() == 0) {
     return remoting::StartHostAsRoot(argc, argv);
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // google_apis::GetOAuth2ClientID/Secret need a static CommandLine.
   base::CommandLine::Init(argc, argv);
@@ -161,7 +161,7 @@ int StartHostMain(int argc, char** argv) {
   // for the account which generated |code|.
   std::string host_owner = command_line->GetSwitchValueASCII("host-owner");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (command_line->HasSwitch("no-start")) {
     // On Linux, registering the host with systemd and starting it is the only
     // reason start_host requires root. The --no-start options skips that final
@@ -171,7 +171,7 @@ int StartHostMain(int argc, char** argv) {
     // controller code, and must be configured on the Linux delegate explicitly.
     DaemonControllerDelegateLinux::set_start_host_after_setup(false);
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 #if defined(OS_WIN)
   // The tool must be run elevated on Windows so the host has access to the
   // directories used to store the configuration JSON files.
