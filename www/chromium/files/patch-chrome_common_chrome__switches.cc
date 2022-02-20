--- chrome/common/chrome_switches.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/common/chrome_switches.cc
@@ -801,7 +801,7 @@ const char kAllowNaClSocketAPI[]            = "allow-n
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN) || defined(OS_FUCHSIA)
+    defined(OS_WIN) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
 // Causes the browser to launch directly in guest mode.
