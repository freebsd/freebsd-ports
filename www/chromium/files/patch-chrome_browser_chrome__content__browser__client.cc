--- chrome/browser/chrome_content_browser_client.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -395,7 +395,7 @@
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
 #include "services/ws/common/switches.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -441,11 +441,11 @@
 #include "components/services/patch/public/interfaces/constants.mojom.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/webshare/share_service_impl.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #endif
@@ -462,7 +462,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -1144,7 +1144,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
 #elif defined(OS_CHROMEOS)
   main_parts = new chromeos::ChromeBrowserMainPartsChromeos(
       parameters, chrome_feature_list_creator_);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts =
       new ChromeBrowserMainPartsLinux(parameters, chrome_feature_list_creator_);
 #elif defined(OS_ANDROID)
@@ -1164,7 +1164,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -1956,7 +1956,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
 #else
@@ -3550,7 +3550,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -4288,7 +4288,7 @@ ChromeContentBrowserClient::CreateThrottlesForNavigati
             handle));
   }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   std::unique_ptr<content::NavigationThrottle> browser_switcher_throttle =
       browser_switcher::BrowserSwitcherNavigationThrottle ::
@@ -4409,7 +4409,7 @@ void ChromeContentBrowserClient::InitWebContextInterfa
 #if defined(OS_ANDROID)
   frame_interfaces_parameterized_->AddInterface(base::Bind(
       &ForwardToJavaWebContentsRegistry<blink::mojom::ShareService>));
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   frame_interfaces_->AddInterface(base::Bind(&ShareServiceImpl::Create));
 #endif
 
@@ -5047,7 +5047,7 @@ std::unique_ptr<content::OverlayWindow>
 ChromeContentBrowserClient::CreateWindowForPictureInPicture(
     content::PictureInPictureWindowController* controller) {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   // Note: content::OverlayWindow::Create() is defined by platform-specific
   // implementation in chrome/browser/ui/views. This layering hack, which goes
   // through //content and ContentBrowserClient, allows us to work around the
