--- ui/views/views_delegate.cc.orig	2015-07-15 16:30:11.000000000 -0400
+++ ui/views/views_delegate.cc	2015-07-22 22:04:39.799216000 -0400
@@ -51,7 +51,7 @@
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return NULL;
 }
@@ -91,7 +91,7 @@
   return program.BaseName().AsUTF8Unsafe();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 scoped_refptr<base::TaskRunner>
     ViewsDelegate::GetTaskRunnerForAuraLinuxAccessibilityInit() {
   return nullptr;
