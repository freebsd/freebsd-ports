--- ui/views/views_delegate.cc.orig	2016-03-25 13:05:04 UTC
+++ ui/views/views_delegate.cc
@@ -70,7 +70,7 @@ HICON ViewsDelegate::GetDefaultWindowIco
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
