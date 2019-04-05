--- src/3rdparty/chromium/ui/views/views_delegate.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/views/views_delegate.cc
@@ -87,7 +87,7 @@ HICON ViewsDelegate::GetSmallWindowIcon() const {
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
