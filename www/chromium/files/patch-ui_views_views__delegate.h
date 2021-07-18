--- ui/views/views_delegate.h.orig	2021-05-12 22:06:47 UTC
+++ ui/views/views_delegate.h
@@ -137,7 +137,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
