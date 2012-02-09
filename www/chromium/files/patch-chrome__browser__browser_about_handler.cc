--- chrome/browser/browser_about_handler.cc.orig	2012-01-18 11:12:44.000000000 +0200
+++ chrome/browser/browser_about_handler.cc	2012-01-29 15:07:44.000000000 +0200
@@ -63,7 +63,7 @@
 #if defined(OS_WIN)
   chrome::kChromeUIConflictsHost,
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   chrome::kChromeUILinuxProxyConfigHost,
   chrome::kChromeUISandboxHost,
 #endif
