--- chrome/browser/chrome_content_browser_client.cc.orig	2019-04-30 22:22:32 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -411,7 +411,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "services/ws/common/switches.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -457,7 +457,7 @@
 #include "components/services/patch/public/interfaces/constants.mojom.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #endif
@@ -474,7 +474,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -1170,7 +1170,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
 #elif defined(OS_CHROMEOS)
   main_parts = new chromeos::ChromeBrowserMainPartsChromeos(
       parameters, chrome_feature_list_creator_);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts =
       new ChromeBrowserMainPartsLinux(parameters, chrome_feature_list_creator_);
 #elif defined(OS_ANDROID)
@@ -1190,7 +1190,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -1994,7 +1994,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
 #else
@@ -3529,7 +3529,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -4281,7 +4281,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
             handle));
   }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   std::unique_ptr<content::NavigationThrottle> browser_switcher_throttle =
       browser_switcher::BrowserSwitcherNavigationThrottle ::
@@ -5115,7 +5115,7 @@ std::unique_ptr<content::OverlayWindow>
 ChromeContentBrowserClient::CreateWindowForPictureInPicture(
     content::PictureInPictureWindowController* controller) {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   // Note: content::OverlayWindow::Create() is defined by platform-specific
   // implementation in chrome/browser/ui/views. This layering hack, which goes
   // through //content and ContentBrowserClient, allows us to work around the
