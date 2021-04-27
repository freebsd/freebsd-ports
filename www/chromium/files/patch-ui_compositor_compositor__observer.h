--- ui/compositor/compositor_observer.h.orig	2021-04-14 18:41:39 UTC
+++ ui/compositor/compositor_observer.h
@@ -48,11 +48,11 @@ class COMPOSITOR_EXPORT CompositorObserver {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   // Called at the top of the compositor's destructor, to give observers a
   // chance to remove themselves.
