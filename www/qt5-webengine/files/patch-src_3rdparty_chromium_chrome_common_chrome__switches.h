--- src/3rdparty/chromium/chrome/common/chrome_switches.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.h
@@ -253,7 +253,7 @@ extern const char kAllowNaClSocketAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
