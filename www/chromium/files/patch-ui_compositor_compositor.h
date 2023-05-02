--- ui/compositor/compositor.h.orig	2023-04-28 17:01:32 UTC
+++ ui/compositor/compositor.h
@@ -452,7 +452,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
