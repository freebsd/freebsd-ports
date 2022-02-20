--- chrome/common/chrome_switches.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/common/chrome_switches.h
@@ -249,7 +249,7 @@ extern const char kAllowNaClSocketAPI[];
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN) || defined(OS_FUCHSIA)
+    defined(OS_WIN) || defined(OS_FUCHSIA) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 #endif
