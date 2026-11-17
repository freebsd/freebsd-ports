--- src/chrome/browser/ui/browser_window/internal/browser_window_features.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/browser_window/internal/browser_window_features.cc
@@ -217,7 +217,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #endif
 
@@ -492,7 +492,7 @@ void BrowserWindowFeatures_ChromiumImpl:
                                                                  browser);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_customization_bubble_sync_controller_ =
       GetUserDataFactory()
           .CreateInstance<ProfileCustomizationBubbleSyncController>(
