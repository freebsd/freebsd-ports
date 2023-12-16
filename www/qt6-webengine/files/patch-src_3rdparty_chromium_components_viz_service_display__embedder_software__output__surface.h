--- src/3rdparty/chromium/components/viz/service/display_embedder/software_output_surface.h.orig	2022-07-22 17:30:31 UTC
+++ src/3rdparty/chromium/components/viz/service/display_embedder/software_output_surface.h
@@ -47,7 +47,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
   gfx::OverlayTransform GetDisplayTransform() override;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -69,7 +69,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
