--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/shared_image_manager.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/shared_image_manager.cc
@@ -756,7 +756,7 @@ bool SharedImageManager::SupportsScanoutImages() {
   return true;
 #elif BUILDFLAG(IS_ANDROID)
   return base::AndroidHardwareBufferCompat::IsSupportAvailable();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // We are in the process of tightening scanout support on Ozone to be guarded
   // by overlays being supported rather than merely native pixmaps being
   // supported, as native pixmap support doesn't always imply that those native
