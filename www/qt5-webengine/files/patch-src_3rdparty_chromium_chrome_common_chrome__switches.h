--- src/3rdparty/chromium/chrome/common/chrome_switches.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.h
@@ -263,7 +263,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 #endif
