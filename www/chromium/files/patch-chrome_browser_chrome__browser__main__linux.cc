--- chrome/browser/chrome_browser_main_linux.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -75,12 +75,14 @@ void ChromeBrowserMainPartsLinux::PrePro
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
@@ -90,7 +92,7 @@ void ChromeBrowserMainPartsLinux::PostMa
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::DBusThreadManagerLinux::Shutdown();
 #endif
