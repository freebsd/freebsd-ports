--- chrome/browser/ui/browser_window/public/browser_window_features.h.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/ui/browser_window/public/browser_window_features.h
@@ -101,7 +101,7 @@ class PinInfoBarController;
 }  // namespace default_browser
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ProfileCustomizationBubbleSyncController;
 namespace session_restore_infobar {
 class SessionRestoreInfobarController;
@@ -449,7 +449,7 @@ class BrowserWindowFeatures {
     return browser_select_file_dialog_controller_.get();
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ProfileCustomizationBubbleSyncController*
   profile_customization_bubble_sync_controller() {
     return profile_customization_bubble_sync_controller_.get();
@@ -619,7 +619,7 @@ class BrowserWindowFeatures {
   std::unique_ptr<BrowserSelectFileDialogController>
       browser_select_file_dialog_controller_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ProfileCustomizationBubbleSyncController>
       profile_customization_bubble_sync_controller_;
 
