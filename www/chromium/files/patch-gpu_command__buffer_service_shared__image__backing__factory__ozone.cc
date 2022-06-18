--- gpu/command_buffer/service/shared_image_backing_factory_ozone.cc.orig	2022-06-17 14:20:10 UTC
+++ gpu/command_buffer/service/shared_image_backing_factory_ozone.cc
@@ -218,7 +218,7 @@ bool SharedImageBackingFactoryOzone::IsSupported(
       !CanImportGpuMemoryBufferToVulkan(gmb_type)) {
     return false;
   }
-#elif BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST)
   bool used_by_skia = (usage & SHARED_IMAGE_USAGE_RASTER) ||
                       (usage & SHARED_IMAGE_USAGE_DISPLAY);
