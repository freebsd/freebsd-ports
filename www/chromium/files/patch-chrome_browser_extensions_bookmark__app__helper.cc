--- chrome/browser/extensions/bookmark_app_helper.cc.orig	2018-11-19 19:55:03.000000000 +0100
+++ chrome/browser/extensions/bookmark_app_helper.cc	2018-12-04 14:45:16.963992000 +0100
@@ -597,7 +597,7 @@
   if (create_shortcuts_) {
 #if !defined(OS_CHROMEOS)
     web_app::ShortcutLocations creation_locations;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     creation_locations.on_desktop = true;
 #else
     creation_locations.on_desktop = false;
