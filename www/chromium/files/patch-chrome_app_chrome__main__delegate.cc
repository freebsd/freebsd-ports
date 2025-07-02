--- chrome/app/chrome_main_delegate.cc.orig	2025-07-02 06:08:04 UTC
+++ chrome/app/chrome_main_delegate.cc
@@ -147,7 +147,7 @@
 #include "components/webui/about/credit_utils.h"
 #endif
 
-#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
 #include "components/nacl/common/nacl_paths.h"
 #include "components/nacl/zygote/nacl_fork_delegate_linux.h"
 #endif
@@ -187,17 +187,17 @@
 #include "v8/include/v8.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
 #include "base/environment.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/scoped_xdg_activation_token_injector.h"
 #include "ui/linux/display_server_utils.h"
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/policy_path_parser.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -315,7 +315,7 @@ void AdjustLinuxOOMScore(const std::string& process_ty
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -398,7 +398,7 @@ bool HandleVersionSwitches(const base::CommandLine& co
   return false;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -410,7 +410,7 @@ void HandleHelpSwitches(const base::CommandLine& comma
 }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
@@ -492,7 +492,7 @@ std::optional<int> AcquireProcessSingleton(
   // process can be exited.
   ChromeProcessSingleton::CreateInstance(user_data_dir);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Read the xdg-activation token and set it in the command line for the
   // duration of the notification in order to ensure this is propagated to an
   // already running browser process if it exists.
@@ -570,7 +570,7 @@ void InitializeUserDataDir(base::CommandLine* command_
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -668,7 +668,7 @@ void RecordMainStartupMetrics(const StartupTimestamps&
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Record the startup process creation time on supported platforms. On Android
   // this is recorded in ChromeMainDelegateAndroid.
   startup_metric_utils::GetCommon().RecordStartupProcessCreationTime(
@@ -827,7 +827,7 @@ std::optional<int> ChromeMainDelegate::PostEarlyInitia
 #if BUILDFLAG(IS_OZONE)
   // Initialize Ozone platform and add required feature flags as per platform's
   // properties.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::SetOzonePlatformForLinuxIfNeeded(*base::CommandLine::ForCurrentProcess());
 #endif
   ui::OzonePlatform::PreEarlyInitialization();
@@ -982,7 +982,7 @@ void ChromeMainDelegate::CommonEarlyInitialization() {
   const bool is_canary_dev = IsCanaryDev();
   const bool emit_crashes =
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       is_canary_dev;
 #else
       false;
@@ -1130,7 +1130,7 @@ std::optional<int> ChromeMainDelegate::BasicStartupCom
     return 0;  // Got a --credits switch; exit with a success error code.
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -1155,7 +1155,7 @@ std::optional<int> ChromeMainDelegate::BasicStartupCom
   ash::RegisterPathProvider();
   chromeos::dbus_paths::RegisterPathProvider();
 #endif
-#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   nacl::RegisterPathProvider();
 #endif
 
@@ -1439,7 +1439,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
     CHECK(!loaded_locale.empty()) << "Locale could not be found for " << locale;
   }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess &&
       !command_line.HasSwitch(switches::kDisableCrashpadForTesting)) {
@@ -1527,13 +1527,13 @@ std::variant<int, content::MainFunctionParams> ChromeM
 #else
 
 #if BUILDFLAG(IS_MAC) || (BUILDFLAG(ENABLE_NACL) && !BUILDFLAG(IS_LINUX) && \
-                          !BUILDFLAG(IS_CHROMEOS))
+                          !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD))
   static const MainFunction kMainFunctions[] = {
 #if BUILDFLAG(IS_MAC)
       {switches::kRelauncherProcess, mac_relauncher::internal::RelauncherMain},
       {switches::kCodeSignCloneCleanupProcess,
        code_sign_clone_manager::internal::ChromeCodeSignCloneCleanupMain},
-#elif BUILDFLAG(ENABLE_NACL) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(ENABLE_NACL) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
       // This entry is not needed on Linux, where the NaCl loader
       // process is launched via nacl_helper instead.
       {switches::kNaClLoaderProcess, NaClMain},
