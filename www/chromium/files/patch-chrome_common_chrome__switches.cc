--- chrome/common/chrome_switches.cc.orig	2017-12-15 02:04:11.000000000 +0100
+++ chrome/common/chrome_switches.cc	2017-12-24 03:10:42.019760000 +0100
@@ -999,12 +999,12 @@
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 #endif
 
