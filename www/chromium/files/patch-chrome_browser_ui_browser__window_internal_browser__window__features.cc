--- chrome/browser/ui/browser_window/internal/browser_window_features.cc.orig	2026-01-21 09:57:21 UTC
+++ chrome/browser/ui/browser_window/internal/browser_window_features.cc
@@ -153,7 +153,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #endif
 
@@ -406,7 +406,7 @@ void BrowserWindowFeatures::Init(BrowserWindowInterfac
   browser_select_file_dialog_controller_ =
       std::make_unique<BrowserSelectFileDialogController>(profile);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_customization_bubble_sync_controller_ =
       std::make_unique<ProfileCustomizationBubbleSyncController>(browser,
                                                                  profile);
