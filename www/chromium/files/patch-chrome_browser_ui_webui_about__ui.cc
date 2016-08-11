--- chrome/browser/ui/webui/about_ui.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/webui/about_ui.cc
@@ -74,7 +74,7 @@
 #include "chrome/browser/ui/webui/theme_source.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #include "content/public/common/sandbox_linux.h"
 #endif
@@ -707,7 +707,7 @@ void FinishMemoryDataRequest(
   }
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -723,6 +723,7 @@ std::string AboutLinuxProxyConfig() {
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, int name_id, bool good) {
   data->append("<tr><td>");
   data->append(l10n_util::GetStringUTF8(name_id));
@@ -791,6 +792,7 @@ std::string AboutSandbox() {
   return data;
 }
 #endif
+#endif
 
 // AboutMemoryHandler ----------------------------------------------------------
 
@@ -963,7 +965,7 @@ void AboutUIHTMLSource::StartDataRequest
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -977,7 +979,7 @@ void AboutUIHTMLSource::StartDataRequest
     ChromeOSCreditsHandler::Start(path, callback);
     return;
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_FREEBSD)
   } else if (source_name_ == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
