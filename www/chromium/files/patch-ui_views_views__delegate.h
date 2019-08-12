--- ui/views/views_delegate.h.orig	2019-07-24 18:59:23 UTC
+++ ui/views/views_delegate.h
@@ -130,7 +130,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // Returns true if the window passed in is in the Windows 8 metro
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_FREEBSD)
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
