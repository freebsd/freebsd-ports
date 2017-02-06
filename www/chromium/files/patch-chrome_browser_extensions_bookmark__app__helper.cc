--- chrome/browser/extensions/bookmark_app_helper.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/extensions/bookmark_app_helper.cc
@@ -707,7 +707,7 @@ void BookmarkAppHelper::FinishInstallati
 #if !defined(OS_MACOSX)
 #if !defined(USE_ASH)
   web_app::ShortcutLocations creation_locations;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   creation_locations.on_desktop = true;
 #else
   creation_locations.on_desktop = false;
