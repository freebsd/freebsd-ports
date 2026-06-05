--- ui/compositor/compositor.cc.orig	2026-06-04 10:12:25 UTC
+++ ui/compositor/compositor.cc
@@ -1000,7 +1000,7 @@ void Compositor::OnResume() {
     obs.ResetIfActive();
 }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   observer_list_.Notify(
       &CompositorObserver::OnCompositingCompleteSwapWithNewSize, this, size);
