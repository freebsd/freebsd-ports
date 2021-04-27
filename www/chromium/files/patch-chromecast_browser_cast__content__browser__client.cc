--- chromecast/browser/cast_content_browser_client.cc.orig	2021-04-14 18:40:58 UTC
+++ chromecast/browser/cast_content_browser_client.cc
@@ -131,9 +131,9 @@
 #include "chromecast/external_mojo/broker_service/broker_service.h"  // nogncheck
 #endif
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
 #include "chromecast/browser/webview/webview_controller.h"
-#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
 
 #if BUILDFLAG(ENABLE_CAST_RENDERER)
 #include "base/sequenced_task_runner.h"
@@ -478,7 +478,7 @@ void CastContentBrowserClient::AppendExtraCommandLineS
                                           switches::kAudioOutputChannels));
     }
   } else if (process_type == switches::kGpuProcess) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // Necessary for accelerated 2d canvas.  By default on Linux, Chromium
     // assumes GLES2 contexts can be lost to a power-save mode, which breaks GPU
     // canvas apps.
@@ -875,12 +875,12 @@ CastContentBrowserClient::CreateThrottlesForNavigation
             handle, general_audience_browsing_service_.get()));
   }
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
   auto webview_throttle = WebviewController::MaybeGetNavigationThrottle(handle);
   if (webview_throttle) {
     throttles.push_back(std::move(webview_throttle));
   }
-#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
 
   return throttles;
 }
