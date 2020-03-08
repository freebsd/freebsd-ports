--- chrome/browser/background/background_mode_manager.cc.orig	2020-03-03 18:53:01 UTC
+++ chrome/browser/background/background_mode_manager.cc
@@ -797,7 +797,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
     return gfx::ImageSkia();
 
   return family->CreateExact(size).AsImageSkia();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif defined(OS_MACOSX)
