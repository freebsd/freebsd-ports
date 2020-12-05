--- chrome/common/chrome_switches.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/common/chrome_switches.cc
@@ -808,7 +808,7 @@ const char kAllowNaClFileHandleAPI[]        = "allow-n
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
