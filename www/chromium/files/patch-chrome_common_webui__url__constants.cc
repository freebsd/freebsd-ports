--- chrome/common/webui_url_constants.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/common/webui_url_constants.cc
@@ -318,7 +318,7 @@ bool IsSystemWebUIHost(base::StringPiece host) {
 }
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 const char kChromeUIHatsHost[] = "hats";
@@ -335,17 +335,17 @@ const char kChromeUINearbyShareURL[] = "chrome://nearb
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
 
@@ -511,13 +511,13 @@ const char* const kChromeHostURLs[] = {
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
