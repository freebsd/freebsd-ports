--- services/on_device_model/ml/on_device_model_executor.cc.orig	2025-12-10 15:04:57 UTC
+++ services/on_device_model/ml/on_device_model_executor.cc
@@ -34,6 +34,7 @@
 #include "services/on_device_model/public/mojom/on_device_model.mojom.h"
 #include "services/on_device_model/public/mojom/on_device_model_service.mojom.h"
 
+// XXX PORT
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 #include "third_party/xnnpack/src/include/xnnpack.h"  // nogncheck
 #endif
