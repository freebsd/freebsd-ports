--- services/on_device_model/ml/on_device_model_executor.cc.orig	2026-01-14 08:33:23 UTC
+++ services/on_device_model/ml/on_device_model_executor.cc
@@ -35,6 +35,7 @@
 #include "services/on_device_model/public/mojom/on_device_model.mojom.h"
 #include "services/on_device_model/public/mojom/on_device_model_service.mojom.h"
 
+// XXX PORT
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 #include "third_party/xnnpack/src/include/xnnpack.h"  // nogncheck
 #endif
