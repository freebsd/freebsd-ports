--- gpu/command_buffer/service/shared_image/ozone_image_backing.cc.orig	2026-07-01 06:24:19 UTC
+++ gpu/command_buffer/service/shared_image/ozone_image_backing.cc
@@ -497,7 +497,7 @@ std::unique_ptr<VulkanImageRepresentation> OzoneImageB
     native_pixmap_handle.planes[1].offset = image_size.GetArea();
     native_pixmap_handle.planes[1].size = image_size.GetArea() / 2;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::CheckedNumeric<uint64_t> checked_required =
         native_pixmap_handle.planes[1].offset;
     checked_required += native_pixmap_handle.planes[1].size;
