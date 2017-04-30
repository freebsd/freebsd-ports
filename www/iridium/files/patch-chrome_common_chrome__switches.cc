--- chrome/common/chrome_switches.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/common/chrome_switches.cc
@@ -1138,7 +1138,7 @@ const char kAllowNaClSocketAPI[]        
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
