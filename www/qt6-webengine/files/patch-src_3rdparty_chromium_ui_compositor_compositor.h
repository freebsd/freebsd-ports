--- src/3rdparty/chromium/ui/compositor/compositor.h.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/ui/compositor/compositor.h
@@ -457,7 +457,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
   // base::PowerSuspendObserver:
   void OnResume() override;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
