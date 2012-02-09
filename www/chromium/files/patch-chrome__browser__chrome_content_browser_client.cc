--- chrome/browser/chrome_content_browser_client.cc.orig	2012-01-18 11:12:43.000000000 +0200
+++ chrome/browser/chrome_content_browser_client.cc	2012-01-29 15:16:06.000000000 +0200
@@ -87,7 +87,7 @@
 #include "chrome/browser/chrome_browser_main_mac.h"
 #elif defined(OS_CHROMEOS)
 #include "chrome/browser/chromeos/chrome_browser_main_chromeos.h"
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_POSIX)
 #include "chrome/browser/chrome_browser_main_posix.h"
@@ -105,7 +105,7 @@
 #include "chrome/browser/chrome_browser_main_extra_parts_aura.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #endif
@@ -264,7 +264,7 @@
   main_parts = new ChromeBrowserMainPartsMac(parameters);
 #elif defined(OS_CHROMEOS)
   main_parts = new ChromeBrowserMainPartsChromeos(parameters);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts = new ChromeBrowserMainPartsLinux(parameters);
 #elif defined(OS_POSIX)
   main_parts = new ChromeBrowserMainPartsPosix(parameters);
