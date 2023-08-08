--- src/3rdparty/chromium/chrome/common/chrome_paths_internal.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_paths_internal.h
@@ -45,7 +45,7 @@ bool GetUserDocumentsDirectory(base::FilePath* result)
 // Get the path to the user's documents directory.
 bool GetUserDocumentsDirectory(base::FilePath* result);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Gets the path to a safe default download directory for a user.
 bool GetUserDownloadsDirectorySafe(base::FilePath* result);
 #endif
