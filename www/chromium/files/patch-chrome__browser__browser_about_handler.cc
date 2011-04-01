--- chrome/browser/browser_about_handler.cc.orig	2011-01-06 10:01:46.000000000 +0100
+++ chrome/browser/browser_about_handler.cc	2011-01-09 20:16:04.000000000 +0100
@@ -74,7 +74,7 @@
 #include "chrome/browser/zygote_host_linux.h"
 #elif defined(OS_MACOSX)
 #include "chrome/browser/ui/cocoa/about_ipc_dialog.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/browser/zygote_host_linux.h"
 #endif
 
@@ -127,7 +127,7 @@
 const char kNetInternalsPath[] = "net-internals";
 const char kPluginsPath[] = "plugins";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 const char kLinuxProxyConfigPath[] = "linux-proxy-config";
 const char kSandboxPath[] = "sandbox";
 #endif
@@ -159,7 +159,7 @@
   kTcmallocPath,
   kTermsPath,
   kVersionPath,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   kSandboxPath,
 #endif
 #if defined(OS_CHROMEOS)
@@ -549,7 +549,7 @@
   return data;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   data.append("<!DOCTYPE HTML>\n");
@@ -796,7 +796,7 @@
   } else if (path == kTermsPath) {
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_TERMS_HTML).as_string();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   } else if (path == kLinuxProxyConfigPath) {
     response = AboutLinuxProxyConfig();
   } else if (path == kSandboxPath) {
