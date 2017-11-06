--- chrome/common/url_constants.cc.orig	2017-09-05 21:05:14.000000000 +0200
+++ chrome/common/url_constants.cc	2017-09-07 14:47:04.280263000 +0200
@@ -146,7 +146,7 @@
 const char kChromeUIMetroFlowURL[] = "chrome://make-metro/";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogURL[] =
     "chrome://tab-modal-confirm-dialog/";
 #endif
@@ -164,7 +164,7 @@
 const char kChromeUICastURL[] = "chrome://cast/";
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
 
@@ -283,7 +283,7 @@
 const char kChromeUISigninDiceInternalsHost[] = "signin-dice-internals";
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 #endif
 
@@ -291,7 +291,7 @@
 const char kChromeUILinuxProxyConfigHost[] = "linux-proxy-config";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
 
@@ -346,7 +346,7 @@
 const char kChromeUIMetroFlowHost[] = "make-metro";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
 #endif
 
@@ -749,7 +749,7 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
     kChromeUILinuxProxyConfigHost,
 #endif
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     kChromeUISandboxHost,
 #endif
 #if defined(OS_WIN)
