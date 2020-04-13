--- ui/views/views_delegate.cc.orig	2020-02-03 21:53:14 UTC
+++ ui/views/views_delegate.cc
@@ -85,7 +85,7 @@ HICON ViewsDelegate::GetSmallWindowIcon() const {
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
