--- chrome/browser/safe_browsing/safe_browsing_pref_change_handler.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/safe_browsing/safe_browsing_pref_change_handler.h
@@ -20,7 +20,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/toasts/toast_controller.h"
 #endif
 
@@ -63,7 +63,7 @@ class SafeBrowsingPrefChangeHandler {
   virtual void MaybeShowEnhancedProtectionSettingChangeNotification();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   void SetToastControllerForTesting(ToastController* controller);
 #endif
 
@@ -72,7 +72,7 @@ class SafeBrowsingPrefChangeHandler {
   raw_ptr<Profile> profile_;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   raw_ptr<ToastController> toast_controller_for_testing_ = nullptr;
 #endif
 
