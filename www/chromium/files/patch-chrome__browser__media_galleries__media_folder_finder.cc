--- chrome/browser/media_galleries/media_folder_finder.cc.orig	2014-10-02 17:39:46 UTC
+++ chrome/browser/media_galleries/media_folder_finder.cc
@@ -50,10 +50,10 @@
   chrome::DIR_USER_APPLICATIONS,
   chrome::DIR_USER_LIBRARY,
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::DIR_CACHE,
 #endif
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   base::DIR_TEMP,
 #endif
 };
