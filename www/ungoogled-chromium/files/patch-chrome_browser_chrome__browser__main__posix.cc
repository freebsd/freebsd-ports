--- chrome/browser/chrome_browser_main_posix.cc.orig	2025-03-09 21:38:10 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -84,7 +84,7 @@ void ExitHandler::ExitWhenPossibleOnUIThread(int signa
   } else {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
