--- chrome/browser/chrome_browser_main_linux.cc.orig	2019-12-16 21:50:42 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -81,14 +81,16 @@ void ChromeBrowserMainPartsLinux::PreProfileInit() {
 void ChromeBrowserMainPartsLinux::PostProfileInit() {
   ChromeBrowserMainPartsPosix::PostProfileInit();
 
+#if !defined(OS_BSD)
   bool enabled = (crash_reporter::IsCrashpadEnabled() &&
                   crash_reporter::GetUploadsEnabled()) ||
                  breakpad::IsCrashReporterEnabled();
   g_browser_process->metrics_service()->RecordBreakpadRegistration(enabled);
+#endif
 }
 
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopStart() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
 #endif
 
@@ -96,7 +98,7 @@ void ChromeBrowserMainPartsLinux::PostMainMessageLoopS
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::BluezDBusThreadManager::Shutdown();
 #endif
