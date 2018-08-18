--- chrome/common/chrome_switches.cc.orig	2018-02-24 16:25:10.000000000 +0100
+++ chrome/common/chrome_switches.cc	2018-03-03 22:30:18.421438000 +0100
@@ -998,12 +998,12 @@
 const char kEnableWaylandServer[] = "enable-wayland-server";
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
 
