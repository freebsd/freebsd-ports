--- chrome/browser/ui/webui/about_ui.cc.orig	2012-10-31 21:02:22.000000000 +0200
+++ chrome/browser/ui/webui/about_ui.cc	2012-11-07 15:58:46.000000000 +0200
@@ -928,7 +928,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -944,6 +944,7 @@
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, const std::string& prefix, int name_id,
                      bool good) {
   data->append("<tr><td>");
@@ -1005,6 +1006,7 @@
   return data;
 }
 #endif
+#endif
 
 std::string AboutVersionStaticContent(const std::string& query) {
   return ResourceBundle::GetSharedInstance().GetRawDataResource(
@@ -1396,7 +1398,7 @@
   } else if (host == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(this, request_id);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
