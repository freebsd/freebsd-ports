--- chrome/common/chrome_switches.h.orig	2017-12-24 03:11:35.192869000 +0100
+++ chrome/common/chrome_switches.h	2017-12-24 03:12:02.641567000 +0100
@@ -313,12 +313,12 @@
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[];
 extern const char kEnableInputImeAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 #endif
 
