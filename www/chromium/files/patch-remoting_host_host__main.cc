--- remoting/host/host_main.cc.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/host_main.cc
@@ -24,7 +24,7 @@
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #include "remoting/base/logging.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/stat.h>
 #include <unistd.h>
 
@@ -70,13 +70,13 @@ int FileChooserMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 int XSessionChooserMain();
 #endif  // BUILDFLAG(IS_LINUX)
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void EnsureVarLibDirectory() {
   if (getuid() != 0) {
     // Only do this in the daemon process, which is always run as root.
@@ -113,7 +113,7 @@ void Usage(const base::FilePath& program_name) {
       "\n"
       "Options:\n"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
       "Linux.\n"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -209,7 +209,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // BUILDFLAG(IS_LINUX)
@@ -273,7 +273,7 @@ int HostMain(int argc, char** argv) {
   // Enable debug logs.
   InitHostLogging();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EnsureVarLibDirectory();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -284,7 +284,7 @@ int HostMain(int argc, char** argv) {
   // Note that we enable crash reporting only if the user has opted in to having
   // the crash reports uploaded.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (command_line->HasSwitch(kCrashpadHandlerSocketFd)) {
       std::string fd_str =
           command_line->GetSwitchValueASCII(kCrashpadHandlerSocketFd);
