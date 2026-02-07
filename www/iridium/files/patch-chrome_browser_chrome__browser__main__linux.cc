--- chrome/browser/chrome_browser_main_linux.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -23,7 +23,7 @@
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/dbus/thread_linux/dbus_thread_linux.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -65,8 +65,10 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(
       dbus_thread_linux::GetSharedSystemBus().get());
+#endif
 
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
@@ -92,7 +94,7 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
   ChromeBrowserMainPartsPosix::PostCreateMainMessageLoop();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopRun() {
   ChromeBrowserMainPartsPosix::PostMainMessageLoopRun();
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
@@ -130,7 +132,7 @@ void ChromeBrowserMainPartsLinux::PostBrowserStart() {
 #endif  // BUILDFLAG(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS)
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No-op; per PostBrowserStart() comment, this is done elsewhere.
 #else
   bluez::BluezDBusManager::Shutdown();
