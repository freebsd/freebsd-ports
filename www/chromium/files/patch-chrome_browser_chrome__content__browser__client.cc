--- chrome/browser/chrome_content_browser_client.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -373,7 +373,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "storage/browser/file_system/external_mount_points.h"
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -437,17 +437,17 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 #if !defined(OS_ANDROID)
 #include "base/debug/leak_annotations.h"
 #include "components/crash/core/app/breakpad_linux.h"
@@ -456,7 +456,7 @@
 #endif
 
 #if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/navigation_throttle.h"
 #endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
@@ -478,11 +478,11 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_extra_parts_linux.h"
 #elif defined(USE_OZONE)
 #include "chrome/browser/chrome_browser_main_extra_parts_ozone.h"
@@ -866,7 +866,7 @@ blink::mojom::AutoplayPolicy GetAutoplayPolicyForWebCo
 int GetCrashSignalFD(const base::CommandLine& command_line) {
   return crashpad::CrashHandlerHost::Get()->GetDeathSignalSocket();
 }
-#elif defined(OS_POSIX) && !defined(OS_MAC)
+#elif defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -1361,7 +1361,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   main_parts = std::make_unique<ChromeBrowserMainPartsLacros>(
       std::move(parameters), &startup_data_);
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   main_parts = std::make_unique<ChromeBrowserMainPartsLinux>(
       std::move(parameters), &startup_data_);
 #elif defined(OS_ANDROID)
@@ -1395,7 +1395,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLacros>());
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   main_parts->AddParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLinux>());
 #else
@@ -1412,7 +1412,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLacros>());
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLinux>());
 #elif defined(USE_OZONE)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsOzone>());
@@ -2184,6 +2184,8 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
 #elif defined(OS_POSIX)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
+#elif defined(OS_BSD)
+  bool enable_crash_reporter = false;
 #else
   bool enable_crash_reporter = false;
   if (crash_reporter::IsCrashpadEnabled()) {
@@ -2497,7 +2499,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
   ThreadProfilerConfiguration::Get()->AppendCommandLineSwitchForChildProcess(
       command_line);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Processes may only query perf_event_open with the BPF sandbox disabled.
   if (browser_command_line.HasSwitch(switches::kEnableThreadInstructionCount) &&
       command_line->HasSwitch(sandbox::policy::switches::kNoSandbox)) {
@@ -3858,7 +3860,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -4266,7 +4268,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
   }
 
 #if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
   MaybeAddThrottle(enterprise_connectors::DeviceTrustNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
@@ -4299,7 +4301,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   MaybeAddThrottle(browser_switcher::BrowserSwitcherNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
