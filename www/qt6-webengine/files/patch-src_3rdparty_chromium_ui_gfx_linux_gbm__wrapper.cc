--- src/3rdparty/chromium/ui/gfx/linux/gbm_wrapper.cc.orig	2025-08-18 00:53:11 UTC
+++ src/3rdparty/chromium/ui/gfx/linux/gbm_wrapper.cc
@@ -331,7 +331,7 @@ class Device final : public ui::GbmDevice {
     // of 1x1 BOs which are destroyed before creating the final BO creation used
     // to instantiate the returned GbmBuffer.
     gfx::Size size_for_verification =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         gfx::Size(1, 1);
 #else
         requested_size;
