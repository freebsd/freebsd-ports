--- chrome/browser/ui/webui/about_ui.cc.orig	2016-07-20 22:03:21.000000000 +0300
+++ chrome/browser/ui/webui/about_ui.cc	2016-08-10 15:53:44.885419000 +0300
@@ -73,7 +73,7 @@
 #include "chrome/browser/ui/webui/theme_source.h"
 #endif

-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #include "content/public/common/sandbox_linux.h"
 #endif
@@ -642,7 +642,7 @@
   DISALLOW_COPY_AND_ASSIGN(AboutDnsHandler);
 };

-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -658,6 +658,7 @@
   return data;
 }

+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, int name_id, bool good) {
   data->append("<tr><td>");
   data->append(l10n_util::GetStringUTF8(name_id));
@@ -672,6 +673,7 @@
   }
   data->append("</td></tr>");
 }
+#endif

 std::string AboutSandbox() {
   std::string data;
@@ -681,6 +683,7 @@
   data.append(l10n_util::GetStringUTF8(IDS_ABOUT_SANDBOX_TITLE));
   data.append("</h1>");

+#if !defined(OS_BSD)
   // Get expected sandboxing status of renderers.
   const int status =
       content::ZygoteHost::GetInstance()->GetRendererSandboxStatus();
@@ -721,6 +724,7 @@
     data.append(l10n_util::GetStringUTF8(IDS_ABOUT_SANDBOX_BAD));
   }
   data.append("</p>");
+#endif

   AppendFooter(&data);
   return data;
@@ -769,7 +773,7 @@
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -778,7 +782,7 @@
     ChromeOSCreditsHandler::Start(path, callback);
     return;
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
