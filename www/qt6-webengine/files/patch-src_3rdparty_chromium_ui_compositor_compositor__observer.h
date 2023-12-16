--- src/3rdparty/chromium/ui/compositor/compositor_observer.h.orig	2022-02-28 16:54:41 UTC
+++ src/3rdparty/chromium/ui/compositor/compositor_observer.h
@@ -48,7 +48,7 @@ class COMPOSITOR_EXPORT CompositorObserver {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}
