--- ui/views/views_delegate.h.orig	2015-08-22 15:02:00.000000000 -0400
+++ ui/views/views_delegate.h	2015-09-03 11:42:15.403898000 -0400
@@ -110,7 +110,7 @@
   // Returns true if the window passed in is in the Windows 8 metro
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_FREEBSD)
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
