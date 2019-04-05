--- src/3rdparty/chromium/ui/views/views_delegate.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/views/views_delegate.h
@@ -155,7 +155,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // Returns true if the window passed in is in the Windows 8 metro
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_FREEBSD)
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
