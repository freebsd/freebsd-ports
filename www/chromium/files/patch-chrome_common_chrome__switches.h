--- chrome/common/chrome_switches.h.orig	2016-05-25 15:00:58.000000000 -0400
+++ chrome/common/chrome_switches.h	2016-05-27 10:00:47.232609000 -0400
@@ -387,7 +387,7 @@
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableInputImeAPI[];
 extern const char kDisableInputImeAPI[];
 #endif
