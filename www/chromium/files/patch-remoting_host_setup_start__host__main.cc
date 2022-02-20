--- remoting/host/setup/start_host_main.cc.orig	2022-02-07 13:39:41 UTC
+++ remoting/host/setup/start_host_main.cc
@@ -32,7 +32,7 @@
 #include <unistd.h>
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "remoting/host/setup/daemon_controller_delegate_linux.h"
 #include "remoting/host/setup/start_host_as_root.h"
 #endif  // defined(OS_LINUX)
@@ -126,7 +126,7 @@ void OnDone(HostStarter::Result result) {
 }  // namespace
 
 int StartHostMain(int argc, char** argv) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Minimize the amount of code that runs as root on Posix systems.
   if (getuid() == 0) {
     return remoting::StartHostAsRoot(argc, argv);
@@ -163,7 +163,7 @@ int StartHostMain(int argc, char** argv) {
   // for the account which generated |code|.
   std::string host_owner = command_line->GetSwitchValueASCII("host-owner");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (command_line->HasSwitch("no-start")) {
     // On Linux, registering the host with systemd and starting it is the only
     // reason start_host requires root. The --no-start options skips that final
