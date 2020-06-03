--- chrome/common/webui_url_constants.cc.orig	2020-05-13 18:40:25 UTC
+++ chrome/common/webui_url_constants.cc
@@ -320,7 +320,7 @@ bool IsSystemWebUIHost(base::StringPiece host) {
 const char kChromeUICastHost[] = "cast";
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 const char kChromeUIHatsHost[] = "hats";
@@ -331,17 +331,17 @@ const char kChromeUIHatsURL[] = "chrome://hats/";
 const char kChromeUILinuxProxyConfigHost[] = "linux-proxy-config";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 const char kChromeUIBrowserSwitchHost[] = "browser-switch";
 const char kChromeUIBrowserSwitchURL[] = "chrome://browser-switch/";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
 #endif
 
@@ -623,13 +623,13 @@ const char* const kChromeHostURLs[] = {
     kChromeUIInternetDetailDialogHost,
     kChromeUIAssistantOptInHost,
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     kChromeUIDiscardsHost,
 #endif
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
     kChromeUILinuxProxyConfigHost,
 #endif
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     kChromeUISandboxHost,
 #endif
 #if defined(OS_WIN)
