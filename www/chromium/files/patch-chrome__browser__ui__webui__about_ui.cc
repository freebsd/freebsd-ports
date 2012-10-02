--- chrome/ui/webui/about_ui.cc.orig	2012-09-25 16:02:14.000000000 +0300
+++ chrome/browser/ui/webui/about_ui.cc	2012-09-29 15:09:43.000000000 +0300
@@ -74,7 +74,7 @@
 #include "chrome/browser/ui/webui/theme_source.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #include "content/public/common/sandbox_linux.h"
 #endif
@@ -924,7 +924,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -1325,7 +1325,7 @@
   } else if (host == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(this, request_id);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -1341,7 +1341,7 @@
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_OS_CREDITS_HTML, ui::SCALE_FACTOR_NONE).as_string();
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
