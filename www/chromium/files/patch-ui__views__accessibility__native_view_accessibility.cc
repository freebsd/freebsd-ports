--- ui/views/accessibility/native_view_accessibility.cc.orig	2015-05-21 11:45:00.287962000 -0400
+++ ui/views/accessibility/native_view_accessibility.cc	2015-05-21 11:45:21.186070000 -0400
@@ -13,7 +13,8 @@
 
 namespace views {
 
-#if !defined(OS_WIN) && !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !defined(OS_WIN) && !(defined(OS_LINUX) && !defined(OS_CHROMEOS)) \
+ && !defined(OS_BSD)
 // static
 NativeViewAccessibility* NativeViewAccessibility::Create(View* view) {
   return new NativeViewAccessibility(view);
