--- chrome/browser/chrome_browser_main_posix.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -142,7 +142,7 @@ void ChromeBrowserMainPartsPosix::PostMainMessageLoopS
 void ChromeBrowserMainPartsPosix::ShowMissingLocaleMessageBox() {
 #if defined(OS_CHROMEOS)
   NOTREACHED();  // Should not ever happen on ChromeOS.
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // Not called on Mac because we load the locale files differently.
   NOTREACHED();
 #elif defined(USE_AURA)
