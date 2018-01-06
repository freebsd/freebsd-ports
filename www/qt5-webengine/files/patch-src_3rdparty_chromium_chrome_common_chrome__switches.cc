--- src/3rdparty/chromium/chrome/common/chrome_switches.cc.orig	2017-01-26 00:49:09 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.cc
@@ -1263,7 +1263,7 @@ const char kAllowNaClSocketAPI[]        
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
