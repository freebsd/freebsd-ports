--- chrome/browser/ui/aura/chrome_browser_main_extra_parts_aura.cc.orig	 2015-05-13 18:23:04.000000000 -0400
+++ chrome/browser/ui/aura/chrome_browser_main_extra_parts_aura.cc  2015-05-21 11:12:51.226717000 -0400
@@ -19,7 +19,7 @@
 #include "ui/gfx/screen.h"
 #include "ui/views/widget/native_widget_aura.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/prefs/pref_service.h"
 #include "chrome/browser/profiles/profile.h"
 #include "chrome/common/pref_names.h"
@@ -137,7 +137,7 @@
 }
 
 void ChromeBrowserMainExtraPartsAura::PreProfileInit() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Now that we have some minimal ui initialized, check to see if we're
   // running as root and bail if we are.
   DetectRunningAsRoot();
@@ -151,7 +151,7 @@
   // after the metrics service is deleted.
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 void ChromeBrowserMainExtraPartsAura::DetectRunningAsRoot() {
   if (getuid() == 0) {
     const base::CommandLine& command_line =
