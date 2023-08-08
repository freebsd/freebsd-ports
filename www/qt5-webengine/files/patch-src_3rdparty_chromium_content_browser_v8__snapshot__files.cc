--- src/3rdparty/chromium/content/browser/v8_snapshot_files.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/browser/v8_snapshot_files.cc
@@ -10,7 +10,7 @@ std::map<std::string, base::FilePath> GetV8SnapshotFil
 namespace content {
 
 std::map<std::string, base::FilePath> GetV8SnapshotFilesToPreload() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(USE_V8_CONTEXT_SNAPSHOT)
   return {{kV8ContextSnapshotDataDescriptor,
            base::FilePath(FILE_PATH_LITERAL(V8_CONTEXT_SNAPSHOT_FILENAME))}};
