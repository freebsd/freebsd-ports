--- chrome/common/url_constants.cc.orig	2017-02-02 02:02:50 UTC
+++ chrome/common/url_constants.cc
@@ -139,7 +139,7 @@ const char kChromeUIMdCupsSettingsURL[] 
 const char kChromeUIMetroFlowURL[] = "chrome://make-metro/";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogURL[] =
     "chrome://tab-modal-confirm-dialog/";
 #endif
@@ -332,7 +332,7 @@ const char kChromeOSAssetPath[] = "/usr/
 const char kChromeUIMetroFlowHost[] = "make-metro";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
 #endif
 
