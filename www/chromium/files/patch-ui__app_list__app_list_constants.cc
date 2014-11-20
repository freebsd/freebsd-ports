--- ui/app_list/app_list_constants.cc.orig	2014-10-10 09:15:32 UTC
+++ ui/app_list/app_list_constants.cc
@@ -94,7 +94,7 @@
 const ui::ResourceBundle::FontStyle kItemTextFontStyle =
     ui::ResourceBundle::SmallBoldFont;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(GOOGLE_CHROME_BUILD)
 const char kAppListWMClass[] = "chrome_app_list";
 #else  // CHROMIUM_BUILD
