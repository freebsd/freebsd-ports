--- chrome/browser/ui/browser_window/internal/browser_window_features.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/browser_window/internal/browser_window_features.cc
@@ -206,7 +206,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #endif
 
@@ -540,7 +540,7 @@ void BrowserWindowFeatures::Init(BrowserWindowInterfac
   call_to_action_lock_ =
       GetUserDataFactory().CreateInstance<CallToActionLock>(*browser, browser);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_customization_bubble_sync_controller_ =
       std::make_unique<ProfileCustomizationBubbleSyncController>(browser,
                                                                  profile);
