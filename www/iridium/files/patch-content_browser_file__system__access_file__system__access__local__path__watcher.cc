--- content/browser/file_system_access/file_system_access_local_path_watcher.cc.orig	2023-11-22 14:00:11 UTC
+++ content/browser/file_system_access/file_system_access_local_path_watcher.cc
@@ -63,7 +63,7 @@ void FileSystemAccessLocalPathWatcher::Initialize(
   base::FilePathWatcher::WatchOptions watch_options {
     .type = scope().IsRecursive() ? base::FilePathWatcher::Type::kRecursive
                                   : base::FilePathWatcher::Type::kNonRecursive,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Note: `report_modified_path` is also present on Android
     // and Fuchsia. Update this switch if support for watching
     // the local file system is added on those platforms.
