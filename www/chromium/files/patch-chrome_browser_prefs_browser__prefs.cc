--- chrome/browser/prefs/browser_prefs.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/prefs/browser_prefs.cc
@@ -315,7 +315,7 @@
 #include "chrome/browser/devtools/devtools_window.h"
 #endif  // BUILDFLAG(ENABLE_DEVTOOLS_FRONTEND)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -498,11 +498,11 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/pref_names.h"  // nogncheck due to crbug.com/1125897
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
@@ -530,7 +530,7 @@
 #include "chrome/browser/sessions/session_service_log.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/color/system_theme.h"
 #endif
 
@@ -1496,7 +1496,7 @@ void RegisterLocalState(PrefRegistrySimple* registry) 
   on_device_translation::RegisterLocalStatePrefs(registry);
 #endif  // BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WhatsNewUI::RegisterLocalStatePrefs(registry);
 #endif
 
@@ -1657,7 +1657,7 @@ void RegisterLocalState(PrefRegistrySimple* registry) 
 #endif  // BUILDFLAG(ENABLE_PDF_SAVE_TO_DRIVE)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kChromeForTestingAllowed, true);
 #endif
 
@@ -2049,13 +2049,13 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   device_signals::RegisterProfilePrefs(registry);
   ntp_tiles::EnterpriseShortcutsManagerImpl::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
   enterprise_signin::RegisterProfilePrefs(registry);
 #endif
