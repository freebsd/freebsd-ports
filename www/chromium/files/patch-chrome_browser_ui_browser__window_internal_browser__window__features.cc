--- chrome/browser/ui/browser_window/internal/browser_window_features.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/browser_window/internal/browser_window_features.cc
@@ -221,7 +221,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #endif
 
@@ -485,7 +485,7 @@ void BrowserWindowFeatures::Init(BrowserWindowInterfac
                                                                  browser);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_customization_bubble_sync_controller_ =
       GetUserDataFactory()
           .CreateInstance<ProfileCustomizationBubbleSyncController>(
