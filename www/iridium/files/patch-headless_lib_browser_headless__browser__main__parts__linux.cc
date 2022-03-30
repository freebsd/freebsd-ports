--- headless/lib/browser/headless_browser_main_parts_linux.cc.orig	2022-03-28 18:11:04 UTC
+++ headless/lib/browser/headless_browser_main_parts_linux.cc
@@ -24,7 +24,7 @@ constexpr char kProductName[] = "HeadlessChrome";
 #endif
 
 void HeadlessBrowserMainParts::PostCreateMainMessageLoop() {
-#if defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 
