--- chrome/browser/safe_browsing/safe_browsing_pref_change_handler.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/safe_browsing/safe_browsing_pref_change_handler.cc
@@ -12,7 +12,7 @@
 #include "content/public/browser/web_contents.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_features.h"
 #include "chrome/browser/ui/toasts/api/toast_id.h"
@@ -59,7 +59,7 @@ SafeBrowsingPrefChangeHandler::~SafeBrowsingPrefChange
 void SafeBrowsingPrefChangeHandler::
     MaybeShowEnhancedProtectionSettingChangeNotification() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!profile_ ||
       !base::FeatureList::IsEnabled(safe_browsing::kEsbAsASyncedSetting)) {
     return;
@@ -186,7 +186,7 @@ void SafeBrowsingPrefChangeHandler::
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void SafeBrowsingPrefChangeHandler::SetToastControllerForTesting(
     ToastController* controller) {
   toast_controller_for_testing_ = controller;
