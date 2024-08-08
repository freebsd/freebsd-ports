--- content/browser/file_system_access/file_path_watcher/file_path_watcher.h.orig	2024-07-30 11:12:21 UTC
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher.h
@@ -125,7 +125,7 @@ class CONTENT_EXPORT FilePathWatcher {
     Type type = Type::kNonRecursive;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // The callback will return the full path to a changed file instead of
     // the watched path supplied as |path| when Watch is called.
     // So the full path can be different from the watched path when a folder is
