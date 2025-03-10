--- headless/lib/browser/headless_browser_main_parts_posix.cc.orig	2025-02-22 18:06:53 UTC
+++ headless/lib/browser/headless_browser_main_parts_posix.cc
@@ -22,13 +22,13 @@
 #include "content/public/browser/browser_thread.h"
 #include "headless/lib/browser/headless_browser_impl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/command_line.h"
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #include "components/os_crypt/sync/os_crypt.h"
 #include "headless/public/switches.h"
 
-#if BUILDFLAG(USE_DBUS)
+#if BUILDFLAG(USE_DBUS) && !BUILDFLAG(IS_BSD)
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #endif
 
@@ -162,7 +162,7 @@ class BrowserShutdownHandler {
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -170,9 +170,9 @@ void HeadlessBrowserMainParts::PostCreateMainMessageLo
   BrowserShutdownHandler::Install(base::BindOnce(
       &HeadlessBrowserImpl::ShutdownWithExitCode, browser_->GetWeakPtr()));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
-#if BUILDFLAG(USE_DBUS)
+#if BUILDFLAG(USE_DBUS) && !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 
