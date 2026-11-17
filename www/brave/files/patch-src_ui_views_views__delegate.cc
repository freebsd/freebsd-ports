--- src/ui/views/views_delegate.cc.orig	2026-10-18 18:43:23 UTC
+++ src/ui/views/views_delegate.cc
@@ -92,7 +92,7 @@ bool ViewsDelegate::IsWindowInMetro(gfx:
   return false;
 }
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
