--- chrome/browser/chrome_content_browser_client.cc.orig	2022-01-20 10:35:49 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -368,7 +368,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "storage/browser/file_system/external_mount_points.h"
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -432,7 +432,7 @@
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #endif
 
@@ -449,10 +449,10 @@
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_ASH)
 #include "chrome/browser/enterprise/connectors/device_trust/navigation_throttle.h"
-#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) ||
+#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
 
 // TODO(crbug.com/939205):  Once the upcoming App Service is available, use a
@@ -471,11 +471,11 @@
 
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
@@ -875,11 +875,13 @@ breakpad::CrashHandlerHostLinux* CreateCrashHandlerHos
 }
 
 int GetCrashSignalFD(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (crash_reporter::IsCrashpadEnabled()) {
     int fd;
     pid_t pid;
     return crash_reporter::GetHandlerSocket(&fd, &pid) ? fd : -1;
   }
+#endif
 
   // Extensions have the same process type as renderers.
   if (command_line.HasSwitch(extensions::switches::kExtensionProcess)) {
@@ -1349,7 +1351,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   main_parts = std::make_unique<ChromeBrowserMainPartsLacros>(parameters,
                                                               &startup_data_);
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   main_parts =
       std::make_unique<ChromeBrowserMainPartsLinux>(parameters, &startup_data_);
 #elif defined(OS_ANDROID)
@@ -1383,7 +1385,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLacros>());
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   main_parts->AddParts(
       std::make_unique<ChromeBrowserMainExtraPartsViewsLinux>());
 #else
@@ -1400,7 +1402,7 @@ ChromeContentBrowserClient::CreateBrowserMainParts(
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLacros>());
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsLinux>());
 #elif defined(USE_OZONE)
   main_parts->AddParts(std::make_unique<ChromeBrowserMainExtraPartsOzone>());
@@ -2176,7 +2178,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
 #else
@@ -3834,7 +3836,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -3869,7 +3871,7 @@ void ChromeContentBrowserClient::GetAdditionalMappedFi
     mappings->Share(kCrashDumpSignal, crash_signal_fd);
   }
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MAC)
+#endif  // defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 std::wstring ChromeContentBrowserClient::GetAppContainerSidForSandboxType(
@@ -4242,12 +4244,12 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
         &throttles);
   }
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_ASH)
   MaybeAddThrottle(enterprise_connectors::DeviceTrustNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
-#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) ||
+#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if !defined(OS_ANDROID)
@@ -4277,7 +4279,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   MaybeAddThrottle(browser_switcher::BrowserSwitcherNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
