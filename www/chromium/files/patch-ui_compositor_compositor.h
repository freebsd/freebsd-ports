--- ui/compositor/compositor.h.orig	2026-03-13 06:02:14 UTC
+++ ui/compositor/compositor.h
@@ -462,7 +462,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
   // base::PowerSuspendObserver:
   void OnResume() override;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
