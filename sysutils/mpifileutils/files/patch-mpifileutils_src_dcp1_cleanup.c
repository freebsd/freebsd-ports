--- mpifileutils/src/dcp1/cleanup.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/dcp1/cleanup.c
@@ -51,8 +51,8 @@ static void DCOPY_truncate_file(DCOPY_operation_t* op,
      * Try the recursive file before file-to-file. The cast below requires us
      * to have a maximum file_size of 2^63, not 2^64.
      */
-    if(truncate64(dest_path_recursive, op->file_size) < 0) {
-        if(truncate64(dest_path_file_to_file, op->file_size) < 0) {
+    if(mfu_truncate(dest_path_recursive, op->file_size) < 0) {
+        if(mfu_truncate(dest_path_file_to_file, op->file_size) < 0) {
             MFU_LOG(MFU_LOG_ERR, "Failed to truncate destination file: %s (errno=%d %s)",
                 dest_path_recursive, errno, strerror(errno));
 
