--- mpifileutils/src/dbcast/dbcast.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/dbcast/dbcast.c
@@ -16,7 +16,12 @@
 #include <string.h>
 #include <getopt.h>
 
+#ifdef __linux__
 #include <sys/vfs.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
 
 // mmap and friends for shared memory
 #include <sys/mman.h>
@@ -32,6 +37,14 @@
  * and send data to each other.  The writer flow controls these worker
  * processes with messages. */
 
+#ifndef HOST_NAME_MAX
+#  ifdef MAXHOSTNAMELEN
+#    define HOST_NAME_MAX MAXHOSTNAMELEN
+#  else
+#    define HOST_NAME_MAX 256
+#  endif
+#endif
+
 #define GCS_SUCCESS (0)
 
 static int gcs_shm_file_key = MPI_KEYVAL_INVALID;
@@ -803,7 +816,7 @@ int main (int argc, char *argv[])
             /* check whether we have space to write the file */
             if (file_size > free_size) {
                 /* not enough space for file */
-                MFU_LOG(MFU_LOG_ERR, "Insufficient space for file `%s` filesize=%llu free=%llu", out_file_path, file_size, free_size);
+                MFU_LOG(MFU_LOG_ERR, "Insufficient space for file `%s` filesize=%llu free=%llu", out_file_path, (unsigned long long)file_size, (unsigned long long)free_size);
                 write_error = 1;
             }
         }
@@ -1118,14 +1131,14 @@ if (node_rank == 0) {
          * a file by the same name but of different size than a previous copy */
         errno = 0;
         if (mfu_truncate(out_file_path, (off_t) file_size) != 0) {
-            MFU_LOG(MFU_LOG_ERR, "Failed to truncate file `%s`", out_file_path, strerror(errno));
+            MFU_LOG(MFU_LOG_ERR, "Failed to truncate file `%s`: %s", out_file_path, strerror(errno));
             write_error = 1;
         }
 
         /* have every writer update file mode */
         errno = 0;
         if (mfu_chmod(out_file_path, (mode_t) mode) != 0) {
-            MFU_LOG(MFU_LOG_ERR, "Failed to chmod file `%s`", out_file_path, strerror(errno));
+            MFU_LOG(MFU_LOG_ERR, "Failed to chmod file `%s`: %s", out_file_path, strerror(errno));
             write_error = 1;
         }
 
@@ -1133,14 +1146,14 @@ if (node_rank == 0) {
         if (write_error) {
             errno = 0;
             if (mfu_unlink(out_file_path) != 0) {
-                MFU_LOG(MFU_LOG_ERR, "Failed to unlink file `%s`", out_file_path, strerror(errno));
+                MFU_LOG(MFU_LOG_ERR, "Failed to unlink file `%s`: %s", out_file_path, strerror(errno));
             }
         }
     } else {
         /* readers close input file */
         errno = 0;
         if (mfu_close(in_file_path, in_file) != 0) {
-            MFU_LOG(MFU_LOG_ERR, "Failed to close file `%s`", in_file_path, strerror(errno));
+            MFU_LOG(MFU_LOG_ERR, "Failed to close file `%s`: %s", in_file_path, strerror(errno));
         }
     }
 
