--- src/3rdparty/chromium/chrome/common/chrome_switches.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.cc
@@ -914,12 +914,12 @@ const char kAllowNaClFileHandleAPI[]        = "allow-n
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 const char kDisableInputImeAPI[] = "disable-input-ime-api";
 const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 #endif
 
