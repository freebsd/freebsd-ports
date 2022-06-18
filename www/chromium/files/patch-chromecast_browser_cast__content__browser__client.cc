--- chromecast/browser/cast_content_browser_client.cc.orig	2022-06-17 14:20:10 UTC
+++ chromecast/browser/cast_content_browser_client.cc
@@ -135,7 +135,7 @@
 #include "extensions/common/constants.h"                            // nogncheck
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_OZONE)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(USE_OZONE)
 #include "chromecast/browser/webview/webview_controller.h"
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_OZONE)
 
@@ -474,7 +474,7 @@ void CastContentBrowserClient::AppendExtraCommandLineS
                                           switches::kAudioOutputChannels));
     }
   } else if (process_type == switches::kGpuProcess) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Necessary for accelerated 2d canvas.  By default on Linux, Chromium
     // assumes GLES2 contexts can be lost to a power-save mode, which breaks GPU
     // canvas apps.
@@ -870,7 +870,7 @@ CastContentBrowserClient::CreateThrottlesForNavigation
             handle, general_audience_browsing_service_.get()));
   }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_OZONE)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(USE_OZONE)
   auto webview_throttle = WebviewController::MaybeGetNavigationThrottle(handle);
   if (webview_throttle) {
     throttles.push_back(std::move(webview_throttle));
