--- remoting/host/host_main.cc.orig	2026-11-19 12:25:27 UTC
+++ remoting/host/host_main.cc
@@ -38,7 +38,7 @@
 #include "remoting/proto/control.pb.h"
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/stat.h>
 #include <unistd.h>
 
@@ -84,13 +84,13 @@ int FileChooserMain();
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
@@ -223,7 +223,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // BUILDFLAG(IS_LINUX)
@@ -338,7 +338,7 @@ int HostMain(int argc, char** argv) {
   }
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EnsureVarLibDirectory();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -349,7 +349,7 @@ int HostMain(int argc, char** argv) {
   // Note that we enable crash reporting only if the user has opted in to having
   // the crash reports uploaded.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (command_line->HasSwitch(kCrashpadHandlerSocketFd)) {
       std::string fd_str =
           command_line->GetSwitchValueASCII(kCrashpadHandlerSocketFd);
