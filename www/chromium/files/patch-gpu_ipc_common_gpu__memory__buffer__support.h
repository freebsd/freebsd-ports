--- gpu/ipc/common/gpu_memory_buffer_support.h.orig	2022-02-28 16:54:41 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.h
@@ -17,7 +17,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
 namespace gfx {
 class ClientNativePixmapFactory;
 }
