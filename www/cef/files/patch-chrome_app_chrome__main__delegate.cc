--- chrome/app/chrome_main_delegate.cc.orig	2026-09-24 16:32:14 UTC
+++ chrome/app/chrome_main_delegate.cc
@@ -104,7 +104,7 @@
 #include "ui/base/ui_base_switches.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif
 
@@ -186,17 +186,17 @@
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
@@ -237,7 +237,7 @@ ChromeMainDelegate::GetNonWildcardDomain
 #endif
       chrome::kChromeSearchScheme,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       webapps::kIsolatedAppScheme,
 #endif
       content::kChromeDevToolsScheme,    content::kChromeUIScheme,
@@ -313,7 +313,7 @@ void AdjustLinuxOOMScore(const std::stri
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -395,7 +395,7 @@ bool HandleVersionSwitches(const base::C
   return false;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -407,7 +407,7 @@ void HandleHelpSwitches(const base::Comm
 }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
@@ -490,7 +490,7 @@ std::optional<int> AcquireProcessSinglet
   // process can be exited.
   ChromeProcessSingleton::CreateInstance(user_data_dir);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Read the xdg-activation token and set it in the command line for the
   // duration of the notification in order to ensure this is propagated to an
   // already running browser process if it exists.
@@ -569,7 +569,7 @@ void InitializeUserDataDir(base::Command
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -679,7 +679,7 @@ void RecordMainStartupMetrics(const Star
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Record the startup process creation time on supported platforms. On Android
   // this is recorded in ChromeMainDelegateAndroid.
   startup_metric_utils::GetCommon().RecordStartupProcessCreationTime(
@@ -1155,7 +1155,7 @@ std::optional<int> ChromeMainDelegate::B
     return 0;  // Got a --credits switch; exit with a success error code.
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -1498,7 +1498,7 @@ void ChromeMainDelegate::PreSandboxStart
   }
 
 #if !BUILDFLAG(ENABLE_CEF)
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess &&
       !command_line.HasSwitch(switches::kDisableCrashpadForTesting)) {
@@ -1544,7 +1544,7 @@ void ChromeMainDelegate::PreSandboxStart
   if (process_type.empty()) {
     // Initialize Ozone platform and add required feature flags as per
     // platform's properties.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ui::SetOzonePlatformForLinuxIfNeeded(
         *base::CommandLine::ForCurrentProcess());
 #endif
