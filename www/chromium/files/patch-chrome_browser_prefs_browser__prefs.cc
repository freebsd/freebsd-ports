--- chrome/browser/prefs/browser_prefs.cc.orig	2019-04-30 22:22:34 UTC
+++ chrome/browser/prefs/browser_prefs.cc
@@ -331,7 +331,7 @@
 #include "chrome/browser/safe_browsing/settings_reset_prompt/settings_reset_prompt_prefs_manager.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
@@ -802,7 +802,7 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
   safe_browsing::PostCleanupSettingsResetter::RegisterProfilePrefs(registry);
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
 #endif
