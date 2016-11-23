--- chrome/common/chrome_switches.cc.orig	2016-10-06 04:02:14.000000000 +0300
+++ chrome/common/chrome_switches.cc	2016-10-13 06:11:21.058074000 +0300
@@ -1277,7 +1277,7 @@
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
