--- chrome/utility/services.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/utility/services.cc
@@ -51,7 +51,7 @@
 #include "services/proxy_resolver_mac/mac_system_proxy_resolver_impl.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/services/system_signals/linux/linux_system_signals_service.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -208,7 +208,7 @@ auto RunMacSystemProxyResolver(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 auto RunSystemSignalsService(
     mojo::PendingReceiver<device_signals::mojom::SystemSignalsService>
         receiver) {
@@ -465,7 +465,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunWindowsIconReader);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   services.Add(RunSystemSignalsService);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
