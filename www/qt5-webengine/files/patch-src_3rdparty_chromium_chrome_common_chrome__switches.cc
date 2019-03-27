--- src/3rdparty/chromium/chrome/common/chrome_switches.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.cc
@@ -987,7 +987,7 @@ const char kAllowNaClFileHandleAPI[]        = "allow-n
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 const char kDisableInputImeAPI[] = "disable-input-ime-api";
 const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
