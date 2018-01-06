--- src/3rdparty/chromium/ui/views/views_delegate.cc.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/views/views_delegate.cc
@@ -71,7 +71,7 @@ HICON ViewsDelegate::GetDefaultWindowIco
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
