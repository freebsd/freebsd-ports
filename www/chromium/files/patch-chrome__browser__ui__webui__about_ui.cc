--- chrome/browser/ui/webui/about_ui.cc.orig	2012-02-01 20:07:00.000000000 +0200
+++ chrome/browser/ui/webui/about_ui.cc	2012-02-01 20:07:54.000000000 +0200
@@ -81,7 +81,7 @@
 #include "chrome/browser/chromeos/version_loader.h"
 #include "chrome/browser/oom_priority_manager.h"
 #include "content/browser/zygote_host_linux.h"
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/browser/zygote_host_linux.h"
 #endif
 
@@ -920,7 +920,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -1306,7 +1306,7 @@
     return;
   } else if (host == chrome::kChromeUIHistogramsHost) {
     response = AboutHistograms(path);
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -1322,7 +1322,7 @@
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_OS_CREDITS_HTML).as_string();
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
