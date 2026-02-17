--- gpu/command_buffer/service/shared_image/shared_image_manager.cc.orig	2026-02-15 10:01:45 UTC
+++ gpu/command_buffer/service/shared_image/shared_image_manager.cc
@@ -624,7 +624,7 @@ bool SharedImageManager::SupportsScanoutImages() {
   return true;
 #elif BUILDFLAG(IS_ANDROID)
   return true;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return supports_overlays_on_ozone_;
 #elif BUILDFLAG(IS_WIN)
   return gl::DirectCompositionTextureSupported();
