--- gpu/ipc/common/gpu_memory_buffer_support.h.orig	2022-02-07 13:39:41 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.h
@@ -17,7 +17,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(USE_OZONE) || defined(OS_BSD)
 namespace gfx {
 class ClientNativePixmapFactory;
 }
