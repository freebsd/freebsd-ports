--- ui/views/views_delegate.cc.orig	2025-09-10 13:22:16 UTC
+++ ui/views/views_delegate.cc
@@ -92,7 +92,7 @@ bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow 
   return false;
 }
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
