--- remoting/host/setup/start_host_main.cc.orig	2025-09-10 13:22:16 UTC
+++ remoting/host/setup/start_host_main.cc
@@ -44,7 +44,7 @@
 #include <unistd.h>
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #include "remoting/host/setup/daemon_controller_delegate_linux.h"
 #include "remoting/host/setup/start_host_as_root.h"
@@ -370,7 +370,7 @@ bool InitializeCloudMachineParams(HostStarter::Params&
 }  // namespace
 
 int StartHostMain(int argc, char** argv) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Minimize the amount of code that runs as root on Posix systems.
   if (getuid() == 0) {
     return remoting::StartHostAsRoot(argc, argv);
@@ -395,7 +395,7 @@ int StartHostMain(int argc, char** argv) {
 
   mojo::core::Init();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch("no-start")) {
     // On Linux, registering the host with systemd and starting it is the only
     // reason start_host requires root. The --no-start options skips that final
@@ -445,7 +445,7 @@ int StartHostMain(int argc, char** argv) {
   // We don't have a config file yet so we can't use IsUsageStatsAllowed(),
   // instead we can just check the command line parameter.
   if (params.enable_crash_reporting) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
