--- components/viz/service/display_embedder/skia_output_device_dawn.cc.orig	2020-07-13 09:36:15 UTC
+++ components/viz/service/display_embedder/skia_output_device_dawn.cc
@@ -14,7 +14,7 @@
 #if defined(OS_WIN)
 #include "third_party/dawn/src/include/dawn_native/D3D12Backend.h"
 #include "ui/gl/vsync_provider_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "third_party/dawn/src/include/dawn_native/VulkanBackend.h"
 #endif
 
