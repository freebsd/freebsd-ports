--- chrome/services/system_signals/public/cpp/system_signals_service_host.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/services/system_signals/public/cpp/system_signals_service_host.cc
@@ -12,7 +12,7 @@
 #include "content/public/browser/service_process_host.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/services/system_signals/mac/mac_system_signals_service.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/services/system_signals/linux/linux_system_signals_service.h"
 #endif
 
@@ -39,7 +39,7 @@ SystemSignalsServiceHost::GetService() {
   return &remote_service_;
 }
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 device_signals::mojom::SystemSignalsService*
 SystemSignalsServiceHost::GetService() {
