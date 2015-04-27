--- chrome/browser/ui/webui/about_ui.cc.orig	2015-04-18 23:56:37.000000000 +0200
+++ chrome/browser/ui/webui/about_ui.cc	2015-04-20 19:06:22.000000000 +0200
@@ -64,7 +64,7 @@
 #include "chrome/browser/ui/webui/theme_source.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #include "content/public/common/sandbox_linux.h"
 #endif
@@ -659,7 +659,7 @@
   }
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -675,6 +675,7 @@
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, int name_id, bool good) {
   data->append("<tr><td>");
   data->append(l10n_util::GetStringUTF8(name_id));
@@ -742,6 +743,7 @@
   return data;
 }
 #endif
+#endif
 
 // AboutMemoryHandler ----------------------------------------------------------
 
@@ -914,7 +916,7 @@
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -928,7 +930,7 @@
     ChromeOSCreditsHandler::Start(path, callback);
     return;
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_FREEBSD)
   } else if (source_name_ == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
