--- ui/compositor/compositor.h.orig	2023-06-05 19:39:05 UTC
+++ ui/compositor/compositor.h
@@ -458,7 +458,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
