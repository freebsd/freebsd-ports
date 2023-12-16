--- src/3rdparty/chromium/content/browser/v8_snapshot_files.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/content/browser/v8_snapshot_files.cc
@@ -13,7 +13,7 @@ namespace content {
 std::map<std::string, absl::variant<base::FilePath, base::ScopedFD>>
 GetV8SnapshotFilesToPreload() {
   std::map<std::string, absl::variant<base::FilePath, base::ScopedFD>> files;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_V8_CONTEXT_SNAPSHOT)
   files[kV8ContextSnapshotDataDescriptor] = base::FilePath(
       FILE_PATH_LITERAL(BUILDFLAG(V8_CONTEXT_SNAPSHOT_FILENAME)));
