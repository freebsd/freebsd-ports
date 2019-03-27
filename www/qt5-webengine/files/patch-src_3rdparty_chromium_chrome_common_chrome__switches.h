--- src/3rdparty/chromium/chrome/common/chrome_switches.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.h
@@ -302,7 +302,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[];
 extern const char kEnableInputImeAPI[];
 #endif
