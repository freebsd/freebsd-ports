--- chrome/browser/prefs/browser_prefs.cc.orig	2019-02-06 22:29:40.393569000 +0100
+++ chrome/browser/prefs/browser_prefs.cc	2019-02-06 22:30:41.131808000 +0100
@@ -313,7 +313,7 @@
 #include "chrome/browser/safe_browsing/settings_reset_prompt/settings_reset_prompt_prefs_manager.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
@@ -764,7 +764,7 @@
   safe_browsing::PostCleanupSettingsResetter::RegisterProfilePrefs(registry);
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   browser_switcher::prefs::RegisterProfilePrefs(registry);
 #endif
