--- src/3rdparty/chromium/base/files/file_path_watcher.h.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/base/files/file_path_watcher.h
@@ -59,7 +59,7 @@ class BASE_EXPORT FilePathWatcher {
     Type type = Type::kNonRecursive;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // The callback will return the full path to a changed file instead of
     // the watched path supplied as |path| when Watch is called.
     // So the full path can be different from the watched path when a folder is
