--- ui/views/views_delegate.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/views/views_delegate.cc
@@ -85,7 +85,7 @@ HICON ViewsDelegate::GetDefaultWindowIcon() const {
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
