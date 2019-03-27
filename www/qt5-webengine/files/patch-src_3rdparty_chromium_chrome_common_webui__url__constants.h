--- src/3rdparty/chromium/chrome/common/webui_url_constants.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/chrome/common/webui_url_constants.h
@@ -232,7 +232,7 @@ extern const char kChromeUICastHost[];
 extern const char kChromeUICastURL[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeUIDiscardsHost[];
 extern const char kChromeUIDiscardsURL[];
 #endif
@@ -241,11 +241,11 @@ extern const char kChromeUIDiscardsURL[];
 extern const char kChromeUILinuxProxyConfigHost[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 extern const char kChromeUISandboxHost[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
 
