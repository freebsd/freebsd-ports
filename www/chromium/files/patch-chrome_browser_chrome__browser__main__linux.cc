--- chrome/browser/chrome_browser_main_linux.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -77,12 +77,14 @@ void ChromeBrowserMainPartsLinux::PreProfileInit() {
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
   bluez::DBusThreadManagerLinux::Initialize();
   bluez::BluezDBusManager::Initialize(
       bluez::DBusThreadManagerLinux::Get()->GetSystemBus(), false);
@@ -92,7 +94,7 @@ void ChromeBrowserMainPartsLinux::PostMainMessageLoopS
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::DBusThreadManagerLinux::Shutdown();
 #endif
