--- chrome/browser/browser_about_handler.cc.orig	2011-04-15 11:01:47.000000000 +0300
+++ chrome/browser/browser_about_handler.cc	2011-04-15 21:51:24.189641560 +0300
@@ -71,7 +71,7 @@
 #include "chrome/browser/chromeos/login/wizard_controller.h"
 #include "chrome/browser/chromeos/version_loader.h"
 #include "content/browser/zygote_host_linux.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "content/browser/zygote_host_linux.h"
 #endif
 
@@ -126,7 +126,7 @@
 const char kPluginsPath[] = "plugins";
 const char kSyncInternalsPath[] = "sync-internals";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 const char kLinuxProxyConfigPath[] = "linux-proxy-config";
 const char kSandboxPath[] = "sandbox";
 #endif
@@ -160,7 +160,7 @@
   kTcmallocPath,
   kTermsPath,
   kVersionPath,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   kSandboxPath,
 #endif
 #if defined(OS_CHROMEOS)
@@ -648,7 +648,7 @@
   return data;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   data.append("<!DOCTYPE HTML>\n");
@@ -863,7 +863,7 @@
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_TERMS_HTML).as_string();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   } else if (path == kLinuxProxyConfigPath) {
     response = AboutLinuxProxyConfig();
   } else if (path == kSandboxPath) {
