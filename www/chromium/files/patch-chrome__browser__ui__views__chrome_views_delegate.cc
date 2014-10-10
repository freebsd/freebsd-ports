--- chrome/browser/ui/views/chrome_views_delegate.cc.orig	2014-10-06 09:19:23.000000000 +0200
+++ chrome/browser/ui/views/chrome_views_delegate.cc	2014-10-06 09:22:54.000000000 +0200
@@ -44,7 +44,7 @@
 #include "ui/views/widget/native_widget_aura.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -234,7 +234,7 @@
   return chrome::IsNativeViewInAsh(window);
 }
 
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
 gfx::ImageSkia* ChromeViewsDelegate::GetDefaultWindowIcon() const {
   ui::ResourceBundle& rb = ui::ResourceBundle::GetSharedInstance();
   return rb.GetImageSkiaNamed(IDR_PRODUCT_LOGO_64);
@@ -373,7 +373,7 @@
 #endif
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
 bool ChromeViewsDelegate::WindowManagerProvidesTitleBar(bool maximized) {
   // On Ubuntu Unity, the system always provides a title bar for maximized
   // windows.
