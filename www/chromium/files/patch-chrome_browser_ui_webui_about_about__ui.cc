--- chrome/browser/ui/webui/about/about_ui.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui/about/about_ui.cc
@@ -407,7 +407,7 @@ using about_ui::AppendHeader;
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data,
@@ -437,7 +437,7 @@ TermsUIConfig::TermsUIConfig()
     : AboutUIConfigBase(chrome::kChromeUITermsHost) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 LinuxProxyConfigUI::LinuxProxyConfigUI()
     : AboutUIConfigBase(chrome::kChromeUILinuxProxyConfigHost) {}
 #endif
@@ -483,7 +483,7 @@ void AboutUIHTMLSource::StartDataRequest(
       response =
           ui::ResourceBundle::GetSharedInstance().LoadDataResourceString(idr);
     }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
