--- chrome/browser/apps/platform_apps/platform_app_launch.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.cc
@@ -21,7 +21,7 @@
 #include "ui/base/page_transition_types.h"
 #include "ui/base/window_open_disposition.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/chrome_app_deprecation.h"
 #include "chrome/browser/extensions/extension_util.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_interface.h"
@@ -92,7 +92,7 @@ bool OpenExtensionApplicationWindow(Profile* profile,
   if (launch_container == LaunchContainer::kLaunchContainerTab)
     return false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return false;
   }
@@ -124,7 +124,7 @@ content::WebContents* OpenExtensionApplicationTab(Prof
   if (launch_container != apps::LaunchContainer::kLaunchContainerTab)
     return nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return nullptr;
   }
@@ -140,7 +140,7 @@ content::WebContents* OpenExtensionApplicationTab(Prof
   return app_tab;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenDeprecatedApplicationPrompt(Profile* profile,
                                      const std::string& app_id) {
   if (!extensions::IsExtensionUnsupportedDeprecatedApp(profile, app_id))
@@ -177,7 +177,7 @@ bool OpenExtensionApplicationWithReenablePrompt(
   if (!GetPlatformApp(profile, app_id))
     return false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return false;
   }
@@ -199,7 +199,7 @@ content::WebContents* OpenExtensionAppShortcutWindow(P
                                          ->enabled_extensions()
                                          .GetAppByURL(url);
   if (app) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (OpenDeprecatedApplicationPrompt(profile, app->id())) {
       return nullptr;
     }
@@ -222,7 +222,7 @@ void RecordExtensionAppLaunchOnTabRestored(Profile* pr
   if (!extension)
     return;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, extension->id())) {
     return;
   }
