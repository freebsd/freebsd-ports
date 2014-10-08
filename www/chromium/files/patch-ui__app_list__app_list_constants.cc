--- ui/app_list/app_list_constants.cc.orig	2014-10-02 17:39:48 UTC
+++ ui/app_list/app_list_constants.cc
@@ -95,7 +95,7 @@
 const ui::ResourceBundle::FontStyle kItemTextFontStyle =
     ui::ResourceBundle::SmallBoldFont;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(GOOGLE_CHROME_BUILD)
 const char kAppListWMClass[] = "chrome_app_list";
 #else  // CHROMIUM_BUILD
