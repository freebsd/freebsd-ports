--- chrome/browser/ui/webui/about_ui.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/browser/ui/webui/about_ui.cc
@@ -574,7 +574,7 @@ std::string ChromeURLs() {
   return html;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -630,7 +630,7 @@ void AboutUIHTMLSource::StartDataRequest(
       response =
           ui::ResourceBundle::GetSharedInstance().LoadDataResourceString(idr);
     }
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
