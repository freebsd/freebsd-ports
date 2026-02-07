--- src/3rdparty/chromium/ui/base/webui/web_ui_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/webui/web_ui_util.cc
@@ -45,7 +45,7 @@ std::string GetFontFamilyMd() {
 constexpr float kMaxScaleFactor = 1000.0f;
 
 std::string GetFontFamilyMd() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Roboto, " + GetFontFamily();
 #else
   return GetFontFamily();
@@ -220,7 +220,7 @@ std::string GetFontFamily() {
 std::string GetFontFamily() {
   std::string font_family = l10n_util::GetStringUTF8(IDS_WEB_FONT_FAMILY);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::CommandLine* cmdline = base::CommandLine::ForCurrentProcess();
   if (!cmdline->HasSwitch(switches::kSingleProcess)) {
     std::string font_name = ui::ResourceBundle::GetSharedInstance()
