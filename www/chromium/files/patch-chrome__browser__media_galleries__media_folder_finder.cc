--- ./chrome/browser/media_galleries/media_folder_finder.cc.orig	2014-08-20 21:01:59.000000000 +0200
+++ ./chrome/browser/media_galleries/media_folder_finder.cc	2014-08-22 15:06:24.000000000 +0200
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
