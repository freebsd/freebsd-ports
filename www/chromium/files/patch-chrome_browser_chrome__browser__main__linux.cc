--- chrome/browser/chrome_browser_main_linux.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -67,7 +67,9 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
+#endif
 
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
@@ -124,7 +126,7 @@ void ChromeBrowserMainPartsLinux::PostBrowserStart() {
 #endif  // defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS)
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No-op; per PostBrowserStart() comment, this is done elsewhere.
 #else
   bluez::BluezDBusManager::Shutdown();
