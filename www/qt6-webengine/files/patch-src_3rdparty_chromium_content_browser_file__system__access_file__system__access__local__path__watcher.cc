--- src/3rdparty/chromium/content/browser/file_system_access/file_system_access_local_path_watcher.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/content/browser/file_system_access/file_system_access_local_path_watcher.cc
@@ -63,7 +63,7 @@ void FileSystemAccessLocalPathWatcher::Initialize(
       .type = scope().IsRecursive() ? FilePathWatcher::Type::kRecursive
                                     : FilePathWatcher::Type::kNonRecursive,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       // Note: `report_modified_path` is also present on Android
       // and Fuchsia. Update this switch if support for watching
       // the local file system is added on those platforms.
