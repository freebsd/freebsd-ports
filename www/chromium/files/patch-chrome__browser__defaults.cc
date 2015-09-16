--- chrome/browser/defaults.cc.orig	2015-04-14 18:31:21.000000000 -0400
+++ chrome/browser/defaults.cc	2015-04-28 10:13:50.737855000 -0400
@@ -41,7 +41,7 @@
 const bool kShowOtherBrowsersInAboutMemory = true;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
