--- gpu/command_buffer/client/test_shared_image_interface.cc.orig	2026-06-05 13:45:06 UTC
+++ gpu/command_buffer/client/test_shared_image_interface.cc
@@ -27,7 +27,7 @@
 #include "ui/gfx/gpu_fence.h"
 #include "ui/gfx/gpu_memory_buffer_handle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <linux/memfd.h>
 #include <sys/mman.h>
 #include <unistd.h>
@@ -426,7 +426,7 @@ TestSharedImageInterface::CreateSharedImageWithAsyncMa
   return image;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 scoped_refptr<ClientSharedImage>
 TestSharedImageInterface::CreateNativePixmapBackedSharedImage(
     const SharedImageInfo& si_info,
