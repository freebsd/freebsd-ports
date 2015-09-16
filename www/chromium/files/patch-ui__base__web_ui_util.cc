--- ui/base/webui/web_ui_util.cc.orig	2015-04-14 18:18:59.000000000 -0400
+++ ui/base/webui/web_ui_util.cc	2015-04-28 08:49:38.687761000 -0400
@@ -174,7 +174,7 @@
 
 // TODO(dnicoara) Remove Ozone check when PlatformFont support is introduced
 // into Ozone: crbug.com/320050
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   font_family = ui::ResourceBundle::GetSharedInstance().GetFont(
       ui::ResourceBundle::BaseFont).GetFontName() + ", " + font_family;
 #endif
