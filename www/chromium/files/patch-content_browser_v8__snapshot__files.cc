--- content/browser/v8_snapshot_files.cc.orig	2020-02-24 18:39:15 UTC
+++ content/browser/v8_snapshot_files.cc
@@ -10,7 +10,7 @@
 namespace content {
 
 std::map<std::string, base::FilePath> GetV8SnapshotFilesToPreload() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(USE_V8_CONTEXT_SNAPSHOT)
   return {{kV8ContextSnapshotDataDescriptor,
            base::FilePath(FILE_PATH_LITERAL("v8_context_snapshot.bin"))}};
