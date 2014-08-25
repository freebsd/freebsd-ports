--- ./ui/app_list/app_list_constants.cc.orig	2014-08-20 21:02:20.000000000 +0200
+++ ./ui/app_list/app_list_constants.cc	2014-08-22 15:06:27.000000000 +0200
@@ -88,7 +88,7 @@
 const ui::ResourceBundle::FontStyle kItemTextFontStyle =
     ui::ResourceBundle::SmallBoldFont;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(GOOGLE_CHROME_BUILD)
 const char kAppListWMClass[] = "chrome_app_list";
 #else  // CHROMIUM_BUILD
