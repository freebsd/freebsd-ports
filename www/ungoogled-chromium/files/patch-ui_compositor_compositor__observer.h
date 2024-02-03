--- ui/compositor/compositor_observer.h.orig	2024-02-03 15:42:55 UTC
+++ ui/compositor/compositor_observer.h
@@ -11,7 +11,7 @@
 #include "components/viz/common/surfaces/frame_sink_id.h"
 #include "ui/compositor/compositor_export.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #endif
 
@@ -49,7 +49,7 @@ class COMPOSITOR_EXPORT CompositorObserver {
   // Called when a child of the compositor is resizing.
   virtual void OnCompositingChildResizing(Compositor* compositor) {}
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(OZONE_PLATFORM_X11)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
