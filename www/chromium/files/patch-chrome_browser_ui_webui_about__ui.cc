--- chrome/browser/ui/webui/about_ui.cc.orig	2018-02-24 16:25:10.000000000 +0100
+++ chrome/browser/ui/webui/about_ui.cc	2018-03-03 22:12:29.265266000 +0100
@@ -390,7 +390,7 @@
   DISALLOW_COPY_AND_ASSIGN(AboutDnsHandler);
 };
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -448,7 +448,7 @@
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
