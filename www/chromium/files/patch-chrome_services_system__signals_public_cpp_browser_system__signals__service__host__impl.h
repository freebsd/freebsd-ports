--- chrome/services/system_signals/public/cpp/browser/system_signals_service_host_impl.h.orig	2022-07-22 17:30:31 UTC
+++ chrome/services/system_signals/public/cpp/browser/system_signals_service_host_impl.h
@@ -11,7 +11,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "components/device_signals/core/common/mojom/system_signals.mojom.h"
 #include "mojo/public/cpp/bindings/remote.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include <memory>
 #include "components/device_signals/core/common/mojom/system_signals.mojom-forward.h"
 #endif
@@ -34,7 +34,7 @@ class SystemSignalsServiceHostImpl
  private:
 #if BUILDFLAG(IS_WIN)
   mojo::Remote<device_signals::mojom::SystemSignalsService> remote_service_;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<device_signals::mojom::SystemSignalsService> local_service_;
 #endif
 };
