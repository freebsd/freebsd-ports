--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2023-03-13 07:33:08 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -172,7 +172,7 @@ bool ExternalVkImageBackingFactory::IsSupported(
 
   // TODO: remove it when below formats are converted to multi plane shared
   // image formats.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   switch (format.resource_format()) {
     case viz::YUV_420_BIPLANAR:
     case viz::YUVA_420_TRIPLANAR:
