--- base/files/file_path_watcher.cc.orig	2019-07-29 18:12:09 UTC
+++ base/files/file_path_watcher.cc
@@ -20,7 +20,7 @@ FilePathWatcher::~FilePathWatcher() {
 // static
 bool FilePathWatcher::RecursiveWatchAvailable() {
 #if (defined(OS_MACOSX) && !defined(OS_IOS)) || defined(OS_WIN) || \
-    defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+    defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
   return true;
 #else
   // FSEvents isn't available on iOS.
