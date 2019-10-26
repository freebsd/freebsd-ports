--- src/3rdparty/chromium/chrome/common/chrome_switches.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.h
@@ -282,12 +282,12 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
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
 
