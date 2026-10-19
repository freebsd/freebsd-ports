--- chrome/browser/ui/browser_window/public/browser_window_features.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/browser_window/public/browser_window_features.h
@@ -127,7 +127,7 @@ class ZoomBubbleManager;
 class WindowsTaskbarIconUpdater;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ProfileCustomizationBubbleSyncController;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -224,7 +224,7 @@ namespace send_tab_to_self {
 class SendTabToSelfToolbarBubbleController;
 }  // namespace send_tab_to_self
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace session_restore_infobar {
 class SessionRestoreInfobarController;
 }  // namespace session_restore_infobar
@@ -527,7 +527,7 @@ class BrowserWindowFeatures {
       pin_infobar_controller_;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ProfileCustomizationBubbleSyncController>
       profile_customization_bubble_sync_controller_;
   std::unique_ptr<session_restore_infobar::SessionRestoreInfobarController>
