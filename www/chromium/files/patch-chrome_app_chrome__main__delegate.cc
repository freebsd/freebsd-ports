--- chrome/app/chrome_main_delegate.cc.orig	2020-11-13 06:36:35 UTC
+++ chrome/app/chrome_main_delegate.cc
@@ -108,7 +108,7 @@
 #include "chrome/app/shutdown_signal_handlers_posix.h"
 #endif
 
-#if BUILDFLAG(ENABLE_NACL) && (defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if BUILDFLAG(ENABLE_NACL) && (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
 #include "components/nacl/common/nacl_paths.h"
 #include "components/nacl/zygote/nacl_fork_delegate_linux.h"
 #endif
@@ -147,12 +147,12 @@
 #include "v8/include/v8.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/environment.h"
 #endif
 
 #if defined(OS_MAC) || defined(OS_WIN) || defined(OS_ANDROID) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/policy/policy_path_parser.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -258,7 +258,7 @@ void SetUpExtendedCrashReporting(bool is_browser_proce
 
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
 void AdjustLinuxOOMScore(const std::string& process_type) {
   int score = -1;
 
@@ -294,13 +294,13 @@ void AdjustLinuxOOMScore(const std::string& process_ty
   if (score > -1)
     base::AdjustOOMScore(base::GetCurrentProcId(), score);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
 
 // Returns true if this subprocess type needs the ResourceBundle initialized
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -339,7 +339,7 @@ bool HandleVersionSwitches(const base::CommandLine& co
   return false;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -349,7 +349,7 @@ void HandleHelpSwitches(const base::CommandLine& comma
     PLOG(FATAL) << "execlp failed";
   }
 }
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #if !defined(OS_MAC) && !defined(OS_ANDROID)
 void SIGTERMProfilingShutdown(int signal) {
@@ -403,7 +403,7 @@ void InitializeUserDataDir(base::CommandLine* command_
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -415,7 +415,7 @@ void InitializeUserDataDir(base::CommandLine* command_
       user_data_dir = base::FilePath::FromUTF8Unsafe(user_data_dir_string);
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_MAC)
   policy::path_parser::CheckUserDataDirPolicy(&user_data_dir);
 #endif  // OS_MAC
@@ -487,7 +487,7 @@ void RecordMainStartupMetrics(base::TimeTicks applicat
 #endif
 
 #if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   // Record the startup process creation time on supported platforms. On Android
   // this is recorded in ChromeMainDelegateAndroid.
   startup_metric_utils::RecordStartupProcessCreationTime(
@@ -705,7 +705,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
   v8_crashpad_support::SetUp();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
   if (!crash_reporter::IsCrashpadEnabled()) {
     breakpad::SetFirstChanceExceptionHandler(v8::TryHandleWebAssemblyTrapPosix);
   }
@@ -716,7 +716,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
     *exit_code = 0;
     return true;  // Got a --version switch; exit with a success error code.
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -744,7 +744,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
 #if defined(OS_CHROMEOS)
   chromeos::RegisterPathProvider();
 #endif
-#if BUILDFLAG(ENABLE_NACL) && (defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if BUILDFLAG(ENABLE_NACL) && (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
   nacl::RegisterPathProvider();
 #endif
 
@@ -924,7 +924,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
 
   crash_reporter::InitializeCrashKeys();
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   ChromeCrashReporterClient::Create();
 #endif
 
@@ -937,7 +937,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
   child_process_logging::Init();
 #endif
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
@@ -1056,7 +1056,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
         locale;
   }
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -1077,7 +1077,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
     }
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MAC)
+#endif  // defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 
 #if defined(OS_ANDROID)
   CHECK_EQ(base::android::GetLibraryProcessType(),
@@ -1097,7 +1097,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
 void ChromeMainDelegate::SandboxInitialized(const std::string& process_type) {
   // Note: If you are adding a new process type below, be sure to adjust the
   // AdjustLinuxOOMScore function too.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
   AdjustLinuxOOMScore(process_type);
 #endif
 #if defined(OS_WIN)
@@ -1139,7 +1139,7 @@ int ChromeMainDelegate::RunProcess(
 
     // This entry is not needed on Linux, where the NaCl loader
     // process is launched via nacl_helper instead.
-#if BUILDFLAG(ENABLE_NACL) && !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if BUILDFLAG(ENABLE_NACL) && !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
     {switches::kNaClLoaderProcess, NaClMain},
 #else
     {"<invalid>", nullptr},  // To avoid constant array of size 0
@@ -1167,7 +1167,7 @@ void ChromeMainDelegate::ProcessExiting(const std::str
 #endif  // !defined(OS_ANDROID)
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
 void ChromeMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<content::ZygoteForkDelegate>>* delegates) {
 #if defined(OS_CHROMEOS)
@@ -1204,7 +1204,7 @@ void ChromeMainDelegate::ZygoteForked() {
   crash_keys::SetCrashKeysFromCommandLine(*command_line);
 }
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
 
 content::ContentClient* ChromeMainDelegate::CreateContentClient() {
   return &chrome_content_client_;
