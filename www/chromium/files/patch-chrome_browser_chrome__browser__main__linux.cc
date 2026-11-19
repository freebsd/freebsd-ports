--- chrome/browser/chrome_browser_main_linux.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -24,7 +24,7 @@
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/containers/to_vector.h"
 #include "chrome/browser/profiles/profile_attributes_entry.h"
 #include "chrome/browser/profiles/profile_attributes_storage.h"
@@ -88,8 +88,10 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
 
 #if !BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(USE_DBUS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(
       dbus_thread_linux::GetSharedSystemBus().get());
+#endif
   session_end_listener_ = SessionEndListenerLinux::Create();
 #endif  // BUILDFLAG(USE_DBUS)
 #endif  // !BUILDFLAG(IS_CHROMEOS)
@@ -97,7 +99,7 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
   ChromeBrowserMainPartsPosix::PostCreateMainMessageLoop();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopRun() {
   ChromeBrowserMainPartsPosix::PostMainMessageLoopRun();
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
@@ -114,7 +116,7 @@ void ChromeBrowserMainPartsLinux::PreProfileInit() {
       base::BindOnce(base::IgnoreResult(&base::GetLinuxDistro)));
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Browser windows pick their WM_CLASS / app_id when they are created, so
   // find out which profiles have a per-profile desktop entry before the first
   // window is opened. This is a handful of stat() calls for profiles other
@@ -151,7 +153,9 @@ void ChromeBrowserMainPartsLinux::PostDestroyThreads()
 #if BUILDFLAG(USE_DBUS)
   session_end_listener_.reset();
 #endif
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Shutdown();
+#endif
   // TODO(shelley.vohr): Call dbus_thread_linux::Shutdown() here. It cannot run
   // yet because the in-process device service (battery, wifi, wake lock) is
   // destroyed after this last BrowserMainParts hook and still dereferences
