--- src/chrome/browser/ui/browser_window/public/browser_window_features.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/browser_window/public/browser_window_features.h
@@ -129,7 +129,7 @@ class ZoomBubbleManager;
 class WindowsTaskbarIconUpdater;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ProfileCustomizationBubbleSyncController;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -226,7 +226,7 @@ namespace send_tab_to_self {
 class SendTabToSelfToolbarBubbleController;
 }  // namespace send_tab_to_self
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace session_restore_infobar {
 class SessionRestoreInfobarController;
 }  // namespace session_restore_infobar
@@ -556,7 +556,7 @@ class BrowserWindowFeatures_ChromiumImpl
       pin_infobar_controller_;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ProfileCustomizationBubbleSyncController>
       profile_customization_bubble_sync_controller_;
   std::unique_ptr<session_restore_infobar::SessionRestoreInfobarController>
