--- gpu/command_buffer/service/shared_image/shared_image_manager.cc.orig	2025-12-10 15:04:57 UTC
+++ gpu/command_buffer/service/shared_image/shared_image_manager.cc
@@ -769,7 +769,7 @@ bool SharedImageManager::SupportsScanoutImages() {
   return true;
 #elif BUILDFLAG(IS_ANDROID)
   return true;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return supports_overlays_on_ozone_;
 #elif BUILDFLAG(IS_WIN)
   return gl::DirectCompositionTextureSupported();
