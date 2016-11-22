--- chrome/common/chrome_switches.h.orig	2016-10-06 04:02:14.000000000 +0300
+++ chrome/common/chrome_switches.h	2016-10-13 06:13:55.604411000 +0300
@@ -378,7 +378,7 @@
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[];
 extern const char kEnableInputImeAPI[];
 #endif
