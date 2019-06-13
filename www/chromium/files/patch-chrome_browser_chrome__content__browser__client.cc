--- chrome/browser/chrome_content_browser_client.cc.orig	2019-06-04 18:55:16 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -418,7 +418,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "services/ws/common/switches.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -467,7 +467,7 @@
 #endif  //  !defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #endif
 
@@ -493,7 +493,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -1197,7 +1197,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
 #elif defined(OS_CHROMEOS)
   main_parts =
       new chromeos::ChromeBrowserMainPartsChromeos(parameters, startup_data_);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts = new ChromeBrowserMainPartsLinux(parameters, startup_data_);
 #elif defined(OS_ANDROID)
   main_parts = new ChromeBrowserMainPartsAndroid(parameters, startup_data_);
@@ -1213,7 +1213,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -2034,7 +2034,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
 #else
@@ -3614,7 +3614,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -4389,7 +4389,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   std::unique_ptr<content::NavigationThrottle> browser_switcher_throttle =
       browser_switcher::BrowserSwitcherNavigationThrottle ::
           MaybeCreateThrottleFor(handle);
@@ -5228,7 +5228,7 @@ bool ChromeContentBrowserClient::HandleExternalProtoco
 std::unique_ptr<content::OverlayWindow>
 ChromeContentBrowserClient::CreateWindowForPictureInPicture(
     content::PictureInPictureWindowController* controller) {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   // Note: content::OverlayWindow::Create() is defined by platform-specific
   // implementation in chrome/browser/ui/views. This layering hack, which goes
