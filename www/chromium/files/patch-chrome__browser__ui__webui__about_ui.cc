--- chrome/browser/ui/webui/about_ui.cc.orig	2012-07-18 10:02:02.000000000 +0300
+++ chrome/browser/ui/webui/about_ui.cc	2012-07-25 20:41:53.000000000 +0300
@@ -72,7 +72,7 @@
 #include "webkit/glue/webkit_glue.h"
 #include "webkit/plugins/webplugininfo.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #include "content/public/common/sandbox_linux.h"
 #endif
@@ -1011,7 +1011,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -1406,7 +1406,7 @@
     return;
   } else if (host == chrome::kChromeUIHistogramsHost) {
     response = AboutHistograms(path);
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -1422,7 +1422,7 @@
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_OS_CREDITS_HTML, ui::SCALE_FACTOR_NONE).as_string();
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
