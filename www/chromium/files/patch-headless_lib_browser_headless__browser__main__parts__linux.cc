--- headless/lib/browser/headless_browser_main_parts_linux.cc.orig	2020-11-13 06:36:44 UTC
+++ headless/lib/browser/headless_browser_main_parts_linux.cc
@@ -10,7 +10,7 @@
 namespace headless {
 
 void HeadlessBrowserMainParts::PostMainMessageLoopStart() {
-#if defined(USE_DBUS) && !defined(OS_CHROMEOS)
+#if defined(USE_DBUS) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 }
