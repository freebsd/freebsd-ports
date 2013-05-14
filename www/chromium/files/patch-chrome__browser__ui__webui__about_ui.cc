--- chrome/browser/ui/webui/about_ui.cc.orig	2013-02-28 10:15:18.000000000 +0200
+++ chrome/browser/ui/webui/about_ui.cc	2013-03-06 20:47:33.000000000 +0200
@@ -740,7 +740,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -756,6 +756,7 @@
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, const std::string& prefix, int name_id,
                      bool good) {
   data->append("<tr><td>");
@@ -818,6 +819,7 @@
   return data;
 }
 #endif
+#endif
 
 // AboutMemoryHandler ----------------------------------------------------------
 
@@ -986,7 +988,7 @@
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
