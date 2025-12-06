--- chrome/utility/services.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/utility/services.cc
@@ -50,7 +50,7 @@
 #include "chrome/services/system_signals/mac/mac_system_signals_service.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/services/system_signals/linux/linux_system_signals_service.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -205,7 +205,7 @@ auto RunMacNotificationService(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 auto RunSystemSignalsService(
     mojo::PendingReceiver<device_signals::mojom::SystemSignalsService>
         receiver) {
@@ -450,7 +450,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunWindowsIconReader);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   services.Add(RunSystemSignalsService);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
