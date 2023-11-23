--- src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.h.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.h
@@ -18,7 +18,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 namespace gfx {
 class ClientNativePixmapFactory;
 }
