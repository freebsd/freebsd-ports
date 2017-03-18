--- chrome/browser/extensions/bookmark_app_helper.cc.orig	2017-03-09 20:04:28 UTC
+++ chrome/browser/extensions/bookmark_app_helper.cc
@@ -716,7 +716,7 @@ void BookmarkAppHelper::FinishInstallati
 #if !defined(OS_MACOSX)
 #if !defined(USE_ASH)
   web_app::ShortcutLocations creation_locations;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   creation_locations.on_desktop = true;
 #else
   creation_locations.on_desktop = false;
