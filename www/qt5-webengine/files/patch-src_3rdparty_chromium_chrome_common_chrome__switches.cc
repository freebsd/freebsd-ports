--- src/3rdparty/chromium/chrome/common/chrome_switches.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.cc
@@ -808,7 +808,7 @@ const char kAllowNaClSocketAPI[]            = "allow-n
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
