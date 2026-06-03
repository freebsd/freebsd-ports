--- remoting/host/host_main.cc.orig	2026-05-09 18:09:27 UTC
+++ remoting/host/host_main.cc
@@ -23,7 +23,7 @@
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #include "remoting/base/logging.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/stat.h>
 #include <unistd.h>
 
@@ -57,7 +57,7 @@ namespace remoting {
 // Known entry points.
 int SingleProcessHostProcessMain();
 int NetworkProcessMain();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 int DaemonProcessMain();
 int DesktopProcessMain();
 #endif
@@ -66,13 +66,13 @@ int FileChooserMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int XSessionChooserMain();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void EnsureVarLibDirectory() {
   if (getuid() != 0) {
     // Only do this in the daemon process, which is always run as root.
@@ -109,7 +109,7 @@ void Usage(const base::FilePath& program_name) {
       "\n"
       "Options:\n"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
       "Linux.\n"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -189,7 +189,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
     main_routine = &SingleProcessHostProcessMain;
   } else if (process_type == kProcessTypeNetwork) {
     main_routine = &NetworkProcessMain;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeDaemon) {
     main_routine = &DaemonProcessMain;
   } else if (process_type == kProcessTypeDesktop) {
@@ -203,7 +203,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -264,7 +264,7 @@ int HostMain(int argc, char** argv) {
   // Enable debug logs.
   InitHostLogging();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EnsureVarLibDirectory();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -275,7 +275,7 @@ int HostMain(int argc, char** argv) {
   // Note that we enable crash reporting only if the user has opted in to having
   // the crash reports uploaded.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     // TODO: joedow - Enable crash reporting for the RDP process.
@@ -319,7 +319,7 @@ int HostMain(int argc, char** argv) {
   // Mac, where the broker process is the agent process broker.
   is_broker_process |= main_routine == &SingleProcessHostProcessMain;
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // For multi-process hosts, the daemon process acts as the broker.
   is_broker_process |= main_routine == &DaemonProcessMain;
 #endif
