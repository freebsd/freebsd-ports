--- chrome/browser/ui/webui/about_ui.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/webui/about_ui.cc
@@ -76,7 +76,7 @@
 #include "chrome/browser/ui/webui/theme_source.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #include "content/public/common/sandbox_linux.h"
 #endif
@@ -644,7 +644,7 @@ class AboutDnsHandler : public base::Ref
   DISALLOW_COPY_AND_ASSIGN(AboutDnsHandler);
 };
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -660,6 +660,7 @@ std::string AboutLinuxProxyConfig() {
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, int name_id, bool good) {
   data->append("<tr><td>");
   data->append(l10n_util::GetStringUTF8(name_id));
@@ -674,6 +675,7 @@ void AboutSandboxRow(std::string* data, 
   }
   data->append("</td></tr>");
 }
+#endif
 
 std::string AboutSandbox() {
   std::string data;
@@ -683,6 +685,7 @@ std::string AboutSandbox() {
   data.append(l10n_util::GetStringUTF8(IDS_ABOUT_SANDBOX_TITLE));
   data.append("</h1>");
 
+#if !defined(OS_BSD)
   // Get expected sandboxing status of renderers.
   const int status =
       content::ZygoteHost::GetInstance()->GetRendererSandboxStatus();
@@ -723,6 +726,7 @@ std::string AboutSandbox() {
     data.append(l10n_util::GetStringUTF8(IDS_ABOUT_SANDBOX_BAD));
   }
   data.append("</p>");
+#endif
 
   AppendFooter(&data);
   return data;
@@ -794,7 +798,7 @@ void AboutUIHTMLSource::StartDataRequest
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -803,7 +807,7 @@ void AboutUIHTMLSource::StartDataRequest
     ChromeOSCreditsHandler::Start(path, callback);
     return;
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
