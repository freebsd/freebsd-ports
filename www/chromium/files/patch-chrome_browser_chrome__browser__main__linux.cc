--- chrome/browser/chrome_browser_main_linux.cc.orig	2020-05-13 18:39:37 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -83,6 +83,7 @@ void ChromeBrowserMainPartsLinux::PreProfileInit() {
 void ChromeBrowserMainPartsLinux::PostProfileInit() {
   ChromeBrowserMainPartsPosix::PostProfileInit();
 
+#if !defined(OS_BSD)
   bool breakpad_registered;
   if (crash_reporter::IsCrashpadEnabled()) {
     // If we're using crashpad, there's no breakpad and crashpad is always
@@ -100,10 +101,11 @@ void ChromeBrowserMainPartsLinux::PostProfileInit() {
   }
   g_browser_process->metrics_service()->RecordBreakpadRegistration(
       breakpad_registered);
+#endif
 }
 
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopStart() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
 #endif
 
@@ -111,7 +113,7 @@ void ChromeBrowserMainPartsLinux::PostMainMessageLoopS
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::BluezDBusThreadManager::Shutdown();
 #endif
