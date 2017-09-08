--- chrome/common/chrome_switches.cc.orig	2017-08-03 00:05:07.000000000 +0200
+++ chrome/common/chrome_switches.cc	2017-08-10 13:31:37.698271000 +0200
@@ -1150,13 +1150,13 @@
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 #endif
 
