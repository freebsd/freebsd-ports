--- chrome/common/url_constants.h.orig	2017-02-02 02:02:50 UTC
+++ chrome/common/url_constants.h
@@ -125,7 +125,7 @@ extern const char kChromeUIMdCupsSetting
 extern const char kChromeUIMetroFlowURL[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogURL[];
 #endif
 
@@ -309,7 +309,7 @@ extern const char kChromeOSAssetPath[];
 extern const char kChromeUIMetroFlowHost[];
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
 
