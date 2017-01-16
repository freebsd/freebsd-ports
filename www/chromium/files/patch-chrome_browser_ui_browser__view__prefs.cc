--- chrome/browser/ui/browser_view_prefs.cc.orig	2016-12-01 23:02:08 UTC
+++ chrome/browser/ui/browser_view_prefs.cc
@@ -10,7 +10,7 @@
 #include "components/prefs/pref_registry_simple.h"
 #include "components/prefs/pref_service.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/x/x11_util.h"  // nogncheck
 #endif
 
@@ -32,7 +32,7 @@ void RegisterBrowserViewLocalPrefs(PrefR
 
 void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   registry->RegisterBooleanPref(prefs::kUseCustomChromeFrame,
                                 ui::GetCustomFramePrefDefault());
 #endif
