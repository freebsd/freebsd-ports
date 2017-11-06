--- chrome/common/url_constants.h.orig	2017-09-05 21:05:14.000000000 +0200
+++ chrome/common/url_constants.h	2017-09-07 14:48:59.551106000 +0200
@@ -133,7 +133,7 @@
 extern const char kChromeUIMetroFlowURL[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogURL[];
 #endif
 
@@ -150,7 +150,7 @@
 extern const char kChromeUICastURL[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeUIDiscardsURL[];
 #endif
 
@@ -265,7 +265,7 @@
 extern const char kChromeUISigninDiceInternalsHost[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeUIDiscardsHost[];
 #endif
 
@@ -326,7 +326,7 @@
 extern const char kChromeUIMetroFlowHost[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
 
