--- src/3rdparty/chromium/ui/compositor/compositor.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/ui/compositor/compositor.h
@@ -453,7 +453,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
