--- src/3rdparty/chromium/ui/views/views_delegate.h.orig	2020-04-08 09:41:36 UTC
+++ src/3rdparty/chromium/ui/views/views_delegate.h
@@ -131,7 +131,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // Returns true if the window passed in is in the Windows 8 metro
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
-#elif defined(OS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
