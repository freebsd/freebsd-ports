--- chrome/common/chrome_switches.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/common/chrome_switches.cc
@@ -1144,7 +1144,7 @@ const char kAllowNaClSocketAPI[]            = "allow-n
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
