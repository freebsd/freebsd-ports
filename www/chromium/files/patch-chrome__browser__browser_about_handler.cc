--- chrome/browser/browser_about_handler.cc.orig	2011-11-01 10:43:20.000000000 +0200
+++ chrome/browser/browser_about_handler.cc	2011-11-19 19:05:28.000000000 +0200
@@ -79,7 +79,7 @@
 #include "chrome/browser/chromeos/version_loader.h"
 #include "chrome/browser/oom_priority_manager.h"
 #include "content/browser/zygote_host_linux.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "content/browser/zygote_host_linux.h"
 #endif
 
@@ -152,7 +152,7 @@
 #if defined(OS_WIN)
   chrome::kChromeUIConflictsHost,
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   chrome::kChromeUILinuxProxyConfigHost,
   chrome::kChromeUISandboxHost,
 #endif
@@ -190,7 +190,7 @@
 #if defined(USE_TCMALLOC)
   chrome::kChromeUITCMallocHost,
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   chrome::kChromeUILinuxProxyConfigHost,
   chrome::kChromeUISandboxHost,
 #endif
@@ -1062,7 +1062,7 @@
   return data;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -1447,7 +1447,7 @@
     return;
   } else if (host == chrome::kChromeUIHistogramsHost) {
     response = AboutHistograms(path);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   } else if (host == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
