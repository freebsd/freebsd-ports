--- chrome/app/chrome_main_delegate.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/app/chrome_main_delegate.cc
@@ -95,7 +95,7 @@
 
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif
 
@@ -163,16 +163,16 @@
 #include "v8/include/v8.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/scoped_xdg_activation_token_injector.h"
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/metrics/system_profile_user_stream.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -228,12 +228,12 @@
 #include "chrome/browser/diagnostics/diagnostics_writer.h"  // nogncheck
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/display_server_utils.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/policy_path_parser.h"  // nogncheck
 #endif
 
@@ -273,7 +273,7 @@ ChromeMainDelegate::GetNonWildcardDomainNonPortSchemes
 #endif
       chrome::kChromeSearchScheme,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       webapps::kIsolatedAppScheme,
 #endif
       content::kChromeDevToolsScheme,    content::kChromeUIScheme,
@@ -401,7 +401,7 @@ void AdjustLinuxOOMScore(const std::string& process_ty
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -494,7 +494,7 @@ bool HandleCreditsSwitch(const base::CommandLine& comm
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -506,7 +506,7 @@ void HandleHelpSwitches(const base::CommandLine& comma
 }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
@@ -597,7 +597,7 @@ std::optional<int> AcquireProcessSingleton(
   // process can be exited.
   ChromeProcessSingleton::CreateInstance(user_data_dir);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Read the xdg-activation token and set it in the command line for the
   // duration of the notification in order to ensure this is propagated to an
   // already running browser process if it exists.
@@ -677,7 +677,7 @@ void InitializeUserDataDir(base::CommandLine* command_
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -787,7 +787,7 @@ void RecordMainStartupMetrics(const StartupTimestamps&
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Record the startup process creation time on supported platforms. On Android
   // this is recorded in ChromeMainDelegateAndroid.
   startup_metric_utils::GetCommon().RecordStartupProcessCreationTime(
@@ -1281,7 +1281,7 @@ std::optional<int> ChromeMainDelegate::BasicStartupCom
     return 0;  // Got a --credits switch; exit with a success error code.
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -1560,7 +1560,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
       command_line.GetSwitchValueASCII(switches::kProcessType);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (process_type.empty()) {
     // Initialize the shared memory that contains the `SystemProfile` only in
     // the browser process. This must happen before Crashpad initialization
@@ -1698,7 +1698,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
     CHECK(!loaded_locale.empty()) << "Locale could not be found for " << locale;
   }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess &&
       !command_line.HasSwitch(switches::kDisableCrashpadForTesting)) {
@@ -1743,7 +1743,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
   if (process_type.empty()) {
     // Initialize Ozone platform and add required feature flags as per
     // platform's properties.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ui::SetOzonePlatformForLinuxIfNeeded(
         *base::CommandLine::ForCurrentProcess());
 #endif
