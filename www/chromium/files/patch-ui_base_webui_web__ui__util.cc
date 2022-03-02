--- ui/base/webui/web_ui_util.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/base/webui/web_ui_util.cc
@@ -221,7 +221,7 @@ std::string GetFontFamily() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   std::string font_name = ui::ResourceBundle::GetSharedInstance()
                               .GetFont(ui::ResourceBundle::BaseFont)
                               .GetFontName();
