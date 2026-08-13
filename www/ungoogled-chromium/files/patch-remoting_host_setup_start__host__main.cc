--- remoting/host/setup/start_host_main.cc.orig	2026-08-13 07:41:05 UTC
+++ remoting/host/setup/start_host_main.cc
@@ -45,7 +45,7 @@
 #include <unistd.h>
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #include "remoting/host/linux/host_types.h"
 #include "remoting/host/setup/daemon_controller_delegate_linux_single_process.h"
@@ -92,7 +92,7 @@ constexpr char kDisableCrashReportingSwitchName[] = "d
 constexpr char kInvalidPinErrorMessage[] =
     "Please provide a numeric PIN consisting of at least six digits.\n";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The host type to use.
 constexpr char kHostTypeSwitchName[] = "host-type";
 #endif
@@ -119,7 +119,7 @@ void PrintDefaultHelpMessage(const char* process_name)
       process_name, kAuthCodeSwitchName, kRedirectUrlSwitchName,
       kDisplayNameSwitchName, kPinSwitchName, kDisableCrashReportingSwitchName);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::cerr << base::StringPrintf(" [--%s=<host type>]", kHostTypeSwitchName)
             << "\n\n";
   HostType::PrintHostTypeHelp();
@@ -135,7 +135,7 @@ void PrintCorpUserHelpMessage(const char* process_name
       "Example usage:\n%s --%s=<username> [--%s=corp-machine-name]",
       process_name, kCorpUserSwitchName, kDisplayNameSwitchName);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::cerr << base::StringPrintf(" [--%s=<host type>]", kHostTypeSwitchName)
             << "\n\n";
   HostType::PrintHostTypeHelp();
@@ -159,7 +159,7 @@ void PrintCloudUserHelpMessage(const char* process_nam
       process_name, kCloudUserSwitchName, kCloudApiKeySwitchName,
       kDisplayNameSwitchName, kDisableCrashReportingSwitchName);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::cerr << base::StringPrintf(" [--%s=<host type>]", kHostTypeSwitchName)
             << "\n\n";
   HostType::PrintHostTypeHelp();
@@ -339,7 +339,7 @@ bool InitializeCorpMachineParams(HostStarter::Params& 
     params.name = command_line->GetSwitchValueASCII(kDisplayNameSwitchName);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(kHostTypeSwitchName)) {
     corp_arg_count++;
   }
@@ -388,7 +388,7 @@ bool InitializeCloudMachineParams(HostStarter::Params&
     cloud_arg_count++;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(kHostTypeSwitchName)) {
     cloud_arg_count++;
   }
@@ -454,7 +454,7 @@ int StartHostMain(int argc, char** argv) {
   }
 #endif  // defined(REMOTING_ENABLE_CRASH_REPORTING)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const HostType* host_type = nullptr;
   if (command_line->HasSwitch(kHostTypeSwitchName)) {
     std::string host_type_name =
@@ -503,7 +503,7 @@ int StartHostMain(int argc, char** argv) {
   }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch("no-start")) {
     // On Linux, registering the host with systemd and starting it is the only
     // reason start_host requires root. The --no-start options skips that final
