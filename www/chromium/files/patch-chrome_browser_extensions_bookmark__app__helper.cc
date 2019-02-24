--- chrome/browser/extensions/bookmark_app_helper.cc.orig	2019-01-30 02:17:45.000000000 +0100
+++ chrome/browser/extensions/bookmark_app_helper.cc	2019-01-31 22:27:52.602150000 +0100
@@ -497,7 +497,7 @@
   if (create_shortcuts_) {
 #if !defined(OS_CHROMEOS)
     web_app::ShortcutLocations creation_locations;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     creation_locations.on_desktop = true;
 #else
     creation_locations.on_desktop = false;
