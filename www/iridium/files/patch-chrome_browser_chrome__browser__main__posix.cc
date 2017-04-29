--- chrome/browser/chrome_browser_main_posix.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -134,7 +134,7 @@ void ChromeBrowserMainPartsPosix::PostMa
 void ChromeBrowserMainPartsPosix::ShowMissingLocaleMessageBox() {
 #if defined(OS_CHROMEOS)
   NOTREACHED();  // Should not ever happen on ChromeOS.
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // Not called on Mac because we load the locale files differently.
   NOTREACHED();
 #elif defined(USE_AURA)
