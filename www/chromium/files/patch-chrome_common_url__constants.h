--- chrome/common/url_constants.h.orig	2017-03-09 20:04:29 UTC
+++ chrome/common/url_constants.h
@@ -128,7 +128,7 @@ extern const char kChromeUIMdCupsSetting
 extern const char kChromeUIMetroFlowURL[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogURL[];
 #endif
 
@@ -313,7 +313,7 @@ extern const char kChromeOSAssetPath[];
 extern const char kChromeUIMetroFlowHost[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
 
