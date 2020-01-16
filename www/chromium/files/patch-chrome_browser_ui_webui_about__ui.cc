--- chrome/browser/ui/webui/about_ui.cc.orig	2019-12-16 21:51:24 UTC
+++ chrome/browser/ui/webui/about_ui.cc
@@ -562,7 +562,7 @@ std::string ChromeURLs() {
   return html;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -616,7 +616,7 @@ void AboutUIHTMLSource::StartDataRequest(
       response =
           ui::ResourceBundle::GetSharedInstance().DecompressDataResource(idr);
     }
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
