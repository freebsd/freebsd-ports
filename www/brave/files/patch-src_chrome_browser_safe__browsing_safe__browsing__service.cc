--- src/chrome/browser/safe_browsing/safe_browsing_service.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/safe_browsing/safe_browsing_service.cc
@@ -81,7 +81,7 @@
 #include "services/preferences/public/mojom/tracked_preference_validation_delegate.mojom.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/safe_browsing/security_settings_bundle_toast_helper.h"
 #endif
 
@@ -172,7 +172,7 @@ void TriggerSecuritySettingsBundleToastI
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (GetSecurityBundleSetting(*profile->GetPrefs()) ==
       SecuritySettingsBundleSetting::ENHANCED) {
     SecuritySettingsBundleToastHelper::GetForProfile(profile.get())
