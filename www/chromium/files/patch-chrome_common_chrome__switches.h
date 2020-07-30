--- chrome/common/chrome_switches.h.orig	2020-07-07 21:58:14 UTC
+++ chrome/common/chrome_switches.h
@@ -255,7 +255,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 #endif
