--- chrome/utility/services.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/utility/services.cc
@@ -50,7 +50,7 @@
 #include "chrome/services/system_signals/mac/mac_system_signals_service.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/services/system_signals/linux/linux_system_signals_service.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -213,7 +213,7 @@ auto RunMacNotificationService(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 auto RunSystemSignalsService(
     mojo::PendingReceiver<device_signals::mojom::SystemSignalsService>
         receiver) {
@@ -481,7 +481,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunWindowsIconReader);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   services.Add(RunSystemSignalsService);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
