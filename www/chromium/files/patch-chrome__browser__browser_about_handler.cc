--- chrome/browser/browser_about_handler.cc.orig	2011-07-28 11:01:59.000000000 +0300
+++ chrome/browser/browser_about_handler.cc	2011-08-28 20:55:56.000000000 +0300
@@ -76,7 +76,7 @@
 #include "chrome/browser/chromeos/login/wizard_controller.h"
 #include "chrome/browser/chromeos/version_loader.h"
 #include "content/browser/zygote_host_linux.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "content/browser/zygote_host_linux.h"
 #endif
 
@@ -146,7 +146,7 @@
 #if defined(OS_WIN)
   chrome::kChromeUIConflictsHost,
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   chrome::kChromeUILinuxProxyConfigHost,
   chrome::kChromeUISandboxHost,
 #endif
@@ -194,7 +194,7 @@
 #if defined(USE_TCMALLOC)
   chrome::kChromeUITCMallocHost,
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   chrome::kChromeUILinuxProxyConfigHost,
   chrome::kChromeUISandboxHost,
 #endif
@@ -993,7 +993,7 @@
   return data;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -1409,7 +1409,7 @@
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_TERMS_HTML).as_string();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   } else if (host == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
   } else if (host == chrome::kChromeUISandboxHost) {
