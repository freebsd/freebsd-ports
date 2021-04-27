--- chrome/browser/ui/webui/about_ui.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/browser/ui/webui/about_ui.cc
@@ -580,7 +580,7 @@ std::string ChromeURLs() {
   return html;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -636,7 +636,7 @@ void AboutUIHTMLSource::StartDataRequest(
       response =
           ui::ResourceBundle::GetSharedInstance().LoadDataResourceString(idr);
     }
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
