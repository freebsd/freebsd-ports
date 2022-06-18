--- chrome/services/system_signals/public/cpp/system_signals_service_host.h.orig	2022-06-17 14:20:10 UTC
+++ chrome/services/system_signals/public/cpp/system_signals_service_host.h
@@ -10,7 +10,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "mojo/public/cpp/bindings/remote.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include <memory>
 #endif
 
@@ -33,7 +33,7 @@ class SystemSignalsServiceHost {
  private:
 #if BUILDFLAG(IS_WIN)
   mojom::Remote<device_signals::mojom::SystemSignalsService> remote_service_;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<device_signals::mojom::SystemSignalsService> local_service_;
 #endif
 };
