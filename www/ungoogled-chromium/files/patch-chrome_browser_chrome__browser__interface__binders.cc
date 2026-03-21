--- chrome/browser/chrome_browser_interface_binders.cc.orig	2026-03-15 18:32:51 UTC
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -84,7 +84,7 @@
 #endif  // BUILDFLAG(ENABLE_UNHANDLED_TAP)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/sub_apps_service_impl.h"
 #endif
 
@@ -522,7 +522,7 @@ void PopulateChromeFrameBinders(
 #endif  // BUILDFLAG(ENABLE_SPEECH_SERVICE)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(blink::features::kSubApps) &&
       !render_frame_host->GetParentOrOuterDocument()) {
     // The service binder will reject non-primary main frames, but we still need
