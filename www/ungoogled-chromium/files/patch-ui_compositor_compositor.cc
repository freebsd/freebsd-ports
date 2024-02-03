--- ui/compositor/compositor.cc.orig	2024-02-03 15:42:55 UTC
+++ ui/compositor/compositor.cc
@@ -893,7 +893,7 @@ void Compositor::OnResume() {
     obs.ResetIfActive();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(OZONE_PLATFORM_X11)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   for (auto& observer : observer_list_)
