--- chrome/common/url_constants.h.orig	2017-04-19 19:06:30 UTC
+++ chrome/common/url_constants.h
@@ -128,7 +128,7 @@ extern const char kChromeUIMdCupsSetting
 extern const char kChromeUIMetroFlowURL[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogURL[];
 #endif
 
@@ -314,7 +314,7 @@ extern const char kChromeOSAssetPath[];
 extern const char kChromeUIMetroFlowHost[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
 
