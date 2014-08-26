--- ./ui/views/views_delegate.cc.orig	2014-08-20 21:02:18.000000000 +0200
+++ ./ui/views/views_delegate.cc	2014-08-22 15:06:27.000000000 +0200
@@ -50,7 +50,7 @@
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return NULL;
 }
