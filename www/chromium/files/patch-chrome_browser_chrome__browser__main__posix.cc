--- chrome/browser/chrome_browser_main_posix.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -70,7 +70,7 @@ void ExitHandler::ExitWhenPossibleOnUIThread(int signa
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
