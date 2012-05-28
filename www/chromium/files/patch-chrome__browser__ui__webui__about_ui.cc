--- chrome/browser/ui/webui/about_ui.cc.orig	2012-04-25 10:02:26.000000000 +0300
+++ chrome/browser/ui/webui/about_ui.cc	2012-04-29 20:28:24.000000000 +0300
@@ -82,7 +82,7 @@
 #include "chrome/browser/chromeos/version_loader.h"
 #include "chrome/browser/oom_priority_manager.h"
 #include "content/public/browser/zygote_host_linux.h"
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #endif
 
@@ -1044,7 +1044,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -1439,7 +1439,7 @@
     return;
   } else if (host == chrome::kChromeUIHistogramsHost) {
     response = AboutHistograms(path);
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -1455,7 +1455,7 @@
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_OS_CREDITS_HTML).as_string();
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (host == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
