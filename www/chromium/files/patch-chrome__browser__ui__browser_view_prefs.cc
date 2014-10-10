--- chrome/browser/ui/browser_view_prefs.cc.orig	2014-10-06 09:19:40.000000000 +0200
+++ chrome/browser/ui/browser_view_prefs.cc	2014-10-06 09:24:45.000000000 +0200
@@ -9,7 +9,7 @@
 #include "chrome/common/pref_names.h"
 #include "components/pref_registry/pref_registry_syncable.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
 #include "ui/base/x/x11_util.h"
 #endif
 
@@ -42,7 +42,7 @@
 void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
   bool custom_frame_default = false;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
   custom_frame_default = ui::GetCustomFramePrefDefault();
 #endif
 
