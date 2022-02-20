--- ui/compositor/compositor_observer.h.orig	2022-02-07 13:39:41 UTC
+++ ui/compositor/compositor_observer.h
@@ -48,7 +48,7 @@ class COMPOSITOR_EXPORT CompositorObserver {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}
