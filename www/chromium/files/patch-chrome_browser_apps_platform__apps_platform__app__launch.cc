--- chrome/browser/apps/platform_apps/platform_app_launch.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.cc
@@ -19,7 +19,7 @@
 #include "extensions/common/constants.h"
 #include "extensions/common/extension.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/chrome_app_deprecation.h"
 #include "chrome/browser/extensions/extension_util.h"
 #include "chrome/browser/ui/browser.h"
@@ -87,7 +87,7 @@ bool OpenExtensionApplicationWindow(Profile* profile,
   if (launch_container == LaunchContainer::kLaunchContainerTab)
     return false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return false;
   }
@@ -119,7 +119,7 @@ content::WebContents* OpenExtensionApplicationTab(Prof
   if (launch_container != apps::LaunchContainer::kLaunchContainerTab)
     return nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return nullptr;
   }
@@ -135,7 +135,7 @@ content::WebContents* OpenExtensionApplicationTab(Prof
   return app_tab;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenDeprecatedApplicationPrompt(Profile* profile,
                                      const std::string& app_id) {
   if (!extensions::IsExtensionUnsupportedDeprecatedApp(profile, app_id))
@@ -171,7 +171,7 @@ bool OpenExtensionApplicationWithReenablePrompt(
   if (!GetPlatformApp(profile, app_id))
     return false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return false;
   }
@@ -193,7 +193,7 @@ content::WebContents* OpenExtensionAppShortcutWindow(P
                                          ->enabled_extensions()
                                          .GetAppByURL(url);
   if (app) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (OpenDeprecatedApplicationPrompt(profile, app->id())) {
       return nullptr;
     }
@@ -216,7 +216,7 @@ void RecordExtensionAppLaunchOnTabRestored(Profile* pr
   if (!extension)
     return;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, extension->id())) {
     return;
   }
