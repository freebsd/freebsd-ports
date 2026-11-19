--- chrome/browser/chrome_browser_main_posix.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -91,7 +91,7 @@ void ExitHandler::ExitWhenPossibleOnUIThread(int signa
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
