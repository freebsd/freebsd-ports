--- ui/views/views_delegate.cc.orig	2014-10-10 08:54:19 UTC
+++ ui/views/views_delegate.cc
@@ -50,7 +50,7 @@
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return NULL;
 }
