--- chrome/browser/background/background_mode_manager.cc.orig	2019-10-21 19:06:20 UTC
+++ chrome/browser/background/background_mode_manager.cc
@@ -769,7 +769,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
     return gfx::ImageSkia();
 
   return family->CreateExact(size).AsImageSkia();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif defined(OS_MACOSX)
