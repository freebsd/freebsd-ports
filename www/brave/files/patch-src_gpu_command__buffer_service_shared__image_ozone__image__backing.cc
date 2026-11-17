--- src/gpu/command_buffer/service/shared_image/ozone_image_backing.cc.orig	2026-10-18 18:43:23 UTC
+++ src/gpu/command_buffer/service/shared_image/ozone_image_backing.cc
@@ -500,7 +500,7 @@ std::unique_ptr<VulkanImageRepresentatio
     native_pixmap_handle.planes[1].offset = image_size.GetArea();
     native_pixmap_handle.planes[1].size = image_size.GetArea() / 2;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::CheckedNumeric<uint64_t> checked_required =
         native_pixmap_handle.planes[1].offset;
     checked_required += native_pixmap_handle.planes[1].size;
