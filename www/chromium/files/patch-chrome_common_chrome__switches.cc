--- chrome/common/chrome_switches.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/common/chrome_switches.cc
@@ -793,7 +793,7 @@ const char kAllowNaClFileHandleAPI[]        = "allow-n
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN) || defined(OS_FUCHSIA)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
