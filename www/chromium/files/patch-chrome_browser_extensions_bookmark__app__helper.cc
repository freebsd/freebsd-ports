--- chrome/browser/extensions/bookmark_app_helper.cc.orig	2016-12-16 03:24:27.367808000 +0000
+++ chrome/browser/extensions/bookmark_app_helper.cc	2016-12-16 03:24:51.798418000 +0000
@@ -707,7 +707,7 @@
 #if !defined(OS_MACOSX)
 #if !defined(USE_ASH)
   web_app::ShortcutLocations creation_locations;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   creation_locations.on_desktop = true;
 #else
   creation_locations.on_desktop = false;
