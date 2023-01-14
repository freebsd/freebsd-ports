--- src/3rdparty/chromium/ui/base/webui/web_ui_util.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/base/webui/web_ui_util.cc
@@ -228,7 +228,7 @@ std::string GetFontFamily() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   const base::CommandLine* cmdline = base::CommandLine::ForCurrentProcess();
   if (!cmdline->HasSwitch(switches::kSingleProcess)) {
     std::string font_name = ui::ResourceBundle::GetSharedInstance()
