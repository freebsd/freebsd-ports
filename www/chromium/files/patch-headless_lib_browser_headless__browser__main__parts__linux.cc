--- headless/lib/browser/headless_browser_main_parts_linux.cc.orig	2020-09-08 19:14:06 UTC
+++ headless/lib/browser/headless_browser_main_parts_linux.cc
@@ -10,7 +10,7 @@
 namespace headless {
 
 void HeadlessBrowserMainParts::PostMainMessageLoopStart() {
-#if defined(USE_DBUS) && !defined(OS_CHROMEOS)
+#if defined(USE_DBUS) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 }
