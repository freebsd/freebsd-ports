--- src/3rdparty/chromium/ui/compositor/compositor_observer.h.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/ui/compositor/compositor_observer.h
@@ -42,11 +42,11 @@ class COMPOSITOR_EXPORT CompositorObserver {
   // Called when a child of the compositor is resizing.
   virtual void OnCompositingChildResizing(Compositor* compositor) {}
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // Called at the top of the compositor's destructor, to give observers a
   // chance to remove themselves.
