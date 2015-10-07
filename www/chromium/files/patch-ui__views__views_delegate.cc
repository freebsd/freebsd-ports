--- ui/views/views_delegate.cc.orig	2015-08-22 15:02:00.000000000 -0400
+++ ui/views/views_delegate.cc	2015-09-03 11:41:11.900854000 -0400
@@ -62,7 +62,7 @@
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
