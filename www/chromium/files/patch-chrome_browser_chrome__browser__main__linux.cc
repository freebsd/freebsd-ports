--- chrome/browser/chrome_browser_main_linux.cc.orig	2018-12-03 21:16:38.000000000 +0100
+++ chrome/browser/chrome_browser_main_linux.cc	2018-12-05 14:26:26.555958000 +0100
@@ -90,12 +90,14 @@
 void ChromeBrowserMainPartsLinux::PostProfileInit() {
   ChromeBrowserMainPartsPosix::PostProfileInit();
 
+#if !defined(OS_BSD)
   g_browser_process->metrics_service()->RecordBreakpadRegistration(
       breakpad::IsCrashReporterEnabled());
+#endif
 }
 
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopStart() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusThreadManager::Initialize();
   bluez::BluezDBusManager::Initialize();
 #endif
@@ -104,7 +106,7 @@
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::BluezDBusThreadManager::Shutdown();
 #endif
