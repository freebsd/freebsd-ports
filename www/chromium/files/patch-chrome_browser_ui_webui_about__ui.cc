--- chrome/browser/ui/webui/about_ui.cc.orig	2019-10-21 19:06:24 UTC
+++ chrome/browser/ui/webui/about_ui.cc
@@ -562,7 +562,7 @@ std::string ChromeURLs() {
   return html;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -617,7 +617,7 @@ void AboutUIHTMLSource::StartDataRequest(
                      .GetRawDataResource(idr)
                      .as_string();
     }
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
