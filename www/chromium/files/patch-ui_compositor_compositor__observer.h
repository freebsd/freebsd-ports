--- ui/compositor/compositor_observer.h.orig	2025-10-02 04:28:32 UTC
+++ ui/compositor/compositor_observer.h
@@ -59,7 +59,7 @@ class COMPOSITOR_EXPORT CompositorObserver {
   virtual void OnChildResizeActivated() {}
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}
