--- gpu/command_buffer/client/test_shared_image_interface.h.orig	2026-01-14 08:33:23 UTC
+++ gpu/command_buffer/client/test_shared_image_interface.h
@@ -136,7 +136,7 @@ class TestSharedImageInterface : public SharedImageInt
       bool premapped,
       const ClientSharedImage::AsyncMapInvokedCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Creates a mappable SI backed by a NativePixmapHandle.
   scoped_refptr<ClientSharedImage> CreateNativePixmapBackedSharedImage(
       const SharedImageInfo& si_info,
