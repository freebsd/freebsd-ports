--- src/3rdparty/chromium/content/browser/v8_snapshot_files.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/browser/v8_snapshot_files.cc
@@ -10,7 +10,7 @@ std::map<std::string, base::FilePath> GetV8SnapshotFil
 namespace content {
 
 std::map<std::string, base::FilePath> GetV8SnapshotFilesToPreload() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(USE_V8_CONTEXT_SNAPSHOT)
   return {{kV8ContextSnapshotDataDescriptor,
            base::FilePath(FILE_PATH_LITERAL(V8_CONTEXT_SNAPSHOT_FILENAME))}};
