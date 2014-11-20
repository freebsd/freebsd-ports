--- chrome/browser/ui/views/chrome_views_delegate.cc.orig	2014-10-10 08:54:11 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.cc
@@ -45,7 +45,7 @@
 #include "ui/views/widget/native_widget_aura.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -235,7 +235,7 @@
   return chrome::IsNativeViewInAsh(window);
 }
 
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 gfx::ImageSkia* ChromeViewsDelegate::GetDefaultWindowIcon() const {
   ui::ResourceBundle& rb = ui::ResourceBundle::GetSharedInstance();
   return rb.GetImageSkiaNamed(IDR_PRODUCT_LOGO_64);
@@ -374,7 +374,7 @@
 #endif
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
 bool ChromeViewsDelegate::WindowManagerProvidesTitleBar(bool maximized) {
   // On Ubuntu Unity, the system always provides a title bar for maximized
   // windows.
