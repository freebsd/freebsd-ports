--- chrome/common/chrome_paths_internal.h.orig	2015-07-18 16:46:40.033337000 -0400
+++ chrome/common/chrome_paths_internal.h	2015-07-18 16:51:35.226378000 -0400
@@ -39,7 +39,7 @@
 // Get the path to the user's documents directory.
 bool GetUserDocumentsDirectory(base::FilePath* result);
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 // Gets the path to a safe default download directory for a user.
 bool GetUserDownloadsDirectorySafe(base::FilePath* result);
 #endif
