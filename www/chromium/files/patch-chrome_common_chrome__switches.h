--- chrome/common/chrome_switches.h.orig	2020-03-03 18:53:53 UTC
+++ chrome/common/chrome_switches.h
@@ -266,7 +266,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 #endif
