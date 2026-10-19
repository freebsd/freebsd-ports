--- chrome/browser/chrome_browser_main_linux.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -22,7 +22,7 @@
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_platform.h"
 #if BUILDFLAG(USE_DBUS)
 #include "components/dbus/thread_linux/dbus_thread_linux.h"
@@ -66,8 +66,10 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
 
 #if !BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(USE_DBUS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(
       dbus_thread_linux::GetSharedSystemBus().get());
+#endif
   session_end_listener_ = SessionEndListenerLinux::Create();
 #endif  // BUILDFLAG(USE_DBUS)
 #endif  // !BUILDFLAG(IS_CHROMEOS)
@@ -75,7 +77,7 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
   ChromeBrowserMainPartsPosix::PostCreateMainMessageLoop();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopRun() {
   ChromeBrowserMainPartsPosix::PostMainMessageLoopRun();
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
@@ -115,7 +117,9 @@ void ChromeBrowserMainPartsLinux::PostDestroyThreads()
 #if BUILDFLAG(USE_DBUS)
   session_end_listener_.reset();
 #endif
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Shutdown();
+#endif
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
   ChromeBrowserMainPartsPosix::PostDestroyThreads();
