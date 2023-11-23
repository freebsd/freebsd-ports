--- src/3rdparty/chromium/headless/lib/browser/headless_browser_main_parts_posix.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_browser_main_parts_posix.cc
@@ -19,13 +19,13 @@
 #include "content/public/browser/browser_thread.h"
 #include "headless/lib/browser/headless_browser_impl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/command_line.h"
 #include "components/os_crypt/key_storage_config_linux.h"
 #include "components/os_crypt/os_crypt.h"
 #include "headless/public/switches.h"
 
-#if defined(USE_DBUS)
+#if defined(USE_DBUS) && !BUILDFLAG(IS_BSD)
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #endif
 
@@ -120,7 +120,7 @@ class BrowserShutdownHandler {
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -128,9 +128,9 @@ void HeadlessBrowserMainParts::PostCreateMainMessageLo
   BrowserShutdownHandler::Install(
       base::BindOnce(&HeadlessBrowserImpl::Shutdown, browser_->GetWeakPtr()));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
-#if defined(USE_DBUS)
+#if defined(USE_DBUS) && !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 
