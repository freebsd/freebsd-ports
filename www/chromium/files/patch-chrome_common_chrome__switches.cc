--- chrome/common/chrome_switches.cc.orig	2021-07-19 18:45:10 UTC
+++ chrome/common/chrome_switches.cc
@@ -810,7 +810,7 @@ const char kAllowNaClFileHandleAPI[]        = "allow-n
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
