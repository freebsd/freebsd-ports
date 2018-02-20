--- chrome/common/url_constants.h.orig	2017-12-15 02:04:12.000000000 +0100
+++ chrome/common/url_constants.h	2017-12-31 04:24:38.490568000 +0100
@@ -136,7 +136,7 @@
 extern const char kChromeUIMetroFlowURL[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogURL[];
 #endif
 
@@ -149,7 +149,7 @@
 extern const char kChromeUICastURL[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeUIDiscardsURL[];
 #endif
 
@@ -262,7 +262,7 @@
 extern const char kChromeUIPrintHost[];
 #endif  // ENABLE_PRINT_PREVIEW
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeUIDiscardsHost[];
 #endif
 
@@ -270,7 +270,7 @@
 extern const char kChromeUILinuxProxyConfigHost[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 extern const char kChromeUISandboxHost[];
 #endif
 
@@ -325,7 +325,7 @@
 extern const char kChromeUIMetroFlowHost[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
 
