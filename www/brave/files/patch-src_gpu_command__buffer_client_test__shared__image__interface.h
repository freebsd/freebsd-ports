--- src/gpu/command_buffer/client/test_shared_image_interface.h.orig	2026-10-18 18:43:23 UTC
+++ src/gpu/command_buffer/client/test_shared_image_interface.h
@@ -138,7 +138,7 @@ class TestSharedImageInterface : public
       bool premapped,
       const ClientSharedImage::AsyncMapInvokedCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Creates a mappable SI backed by a NativePixmapHandle.
   scoped_refptr<ClientSharedImage> CreateNativePixmapBackedSharedImage(
       const SharedImageInfo& si_info,
