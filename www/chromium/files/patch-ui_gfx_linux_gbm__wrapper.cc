--- ui/gfx/linux/gbm_wrapper.cc.orig	2023-12-10 06:10:27 UTC
+++ ui/gfx/linux/gbm_wrapper.cc
@@ -316,7 +316,7 @@ class Device final : public ui::GbmDevice {
     // of 1x1 BOs which are destroyed before creating the final BO creation used
     // to instantiate the returned GbmBuffer.
     gfx::Size size =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         gfx::Size(1, 1);
 #else
         requested_size;
