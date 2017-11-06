--- chrome/common/chrome_switches.h.orig	2017-08-03 00:05:07.000000000 +0200
+++ chrome/common/chrome_switches.h	2017-08-10 13:31:51.802319000 +0200
@@ -349,13 +349,13 @@
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[];
 extern const char kEnableInputImeAPI[];
 #endif
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 #endif
 
