--- base/files/file_util_posix.cc.orig	2024-07-30 11:12:21 UTC
+++ base/files/file_util_posix.cc
@@ -889,36 +889,33 @@ bool CreateNewTempDirectory(const FilePath::StringType
 bool CreateDirectoryAndGetError(const FilePath& full_path, File::Error* error) {
   ScopedBlockingCall scoped_blocking_call(
       FROM_HERE, BlockingType::MAY_BLOCK);  // For call to mkdir().
+  const FilePath kFileSystemRoot("/");
   std::vector<FilePath> subpaths;
 
   // Collect a list of all parent directories.
   FilePath last_path = full_path;
-  subpaths.push_back(full_path);
-  for (FilePath path = full_path.DirName(); path.value() != last_path.value();
-       path = path.DirName()) {
+  if (full_path != kFileSystemRoot)
+    subpaths.push_back(full_path);
+  for (FilePath path = full_path.DirName(); (path.value() != last_path.value() &&
+       (path != kFileSystemRoot)); path = path.DirName()) {
     subpaths.push_back(path);
     last_path = path;
   }
 
   // Iterate through the parents and create the missing ones.
   for (const FilePath& subpath : base::Reversed(subpaths)) {
-    if (DirectoryExists(subpath)) {
-      continue;
-    }
-    if (mkdir(subpath.value().c_str(), 0700) == 0) {
-      continue;
-    }
-    // Mkdir failed, but it might have failed with EEXIST, or some other error
-    // due to the directory appearing out of thin air. This can occur if
-    // two processes are trying to create the same file system tree at the same
-    // time. Check to see if it exists and make sure it is a directory.
-    int saved_errno = errno;
-    if (!DirectoryExists(subpath)) {
-      if (error) {
-        *error = File::OSErrorToFileError(saved_errno);
+    if (!PathExists(subpath)) {
+      if ((mkdir(subpath.value().c_str(), 0700) == -1) &&
+          ((full_path != subpath) ? (errno != ENOENT) : (-1))) {
+        int saved_errno = errno;
+        if (error)
+          *error = File::OSErrorToFileError(saved_errno);
+        return false;
       }
-      errno = saved_errno;
-      return false;
+    } else if (!DirectoryExists(subpath)) {
+        if (error)
+          *error = File::OSErrorToFileError(ENOTDIR);
+        return false;
     }
   }
   return true;
