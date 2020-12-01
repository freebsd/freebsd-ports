--- chrome/common/chrome_paths_internal.h.orig	2020-11-13 06:36:38 UTC
+++ chrome/common/chrome_paths_internal.h
@@ -45,7 +45,7 @@ void GetUserCacheDirectory(const base::FilePath& profi
 // Get the path to the user's documents directory.
 bool GetUserDocumentsDirectory(base::FilePath* result);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Gets the path to a safe default download directory for a user.
 bool GetUserDownloadsDirectorySafe(base::FilePath* result);
 #endif
