--- chrome/common/chrome_switches.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/common/chrome_switches.cc
@@ -1165,7 +1165,7 @@ const char kAllowNaClSocketAPI[]        
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
