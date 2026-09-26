--- chrome/browser/chrome_browser_main_posix.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -77,7 +77,7 @@ void ExitHandler::ExitWhenPossibleOnUIThread(int signa
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
