--- ui/compositor/compositor.h.orig	2024-02-03 15:42:55 UTC
+++ ui/compositor/compositor.h
@@ -56,7 +56,7 @@
 #include "ui/gfx/native_widget_types.h"
 #include "ui/gfx/overlay_transform.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #endif
 
@@ -464,7 +464,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
   // base::PowerSuspendObserver:
   void OnResume() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(OZONE_PLATFORM_X11)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif  // BUILDFLAG(OZONE_PLATFORM_X11)
