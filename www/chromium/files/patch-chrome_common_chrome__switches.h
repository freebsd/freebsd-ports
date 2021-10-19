--- chrome/common/chrome_switches.h.orig	2021-09-24 04:26:00 UTC
+++ chrome/common/chrome_switches.h
@@ -250,7 +250,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN) || defined(OS_FUCHSIA)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
