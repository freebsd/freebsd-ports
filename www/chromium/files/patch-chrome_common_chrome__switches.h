--- chrome/common/chrome_switches.h.orig	2021-12-31 00:57:25 UTC
+++ chrome/common/chrome_switches.h
@@ -247,7 +247,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN) || defined(OS_FUCHSIA)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
