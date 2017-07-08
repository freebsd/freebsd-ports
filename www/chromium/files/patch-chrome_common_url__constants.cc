--- chrome/common/url_constants.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/common/url_constants.cc
@@ -145,7 +145,7 @@ const char kChromeUICleanupToolURL[] = "chrome://clean
 const char kChromeUIMetroFlowURL[] = "chrome://make-metro/";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogURL[] =
     "chrome://tab-modal-confirm-dialog/";
 #endif
@@ -161,7 +161,7 @@ const char kChromeUICastURL[] = "chrome://cast/";
 #endif
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
@@ -340,7 +340,7 @@ const char kChromeUICleanupToolHost[] = "cleanup";
 const char kChromeUIMetroFlowHost[] = "make-metro";
 #endif
 
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
 #endif
 
