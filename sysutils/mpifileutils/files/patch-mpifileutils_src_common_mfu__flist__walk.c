--- mpifileutils/src/common/mfu_flist_walk.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_flist_walk.c
@@ -186,8 +186,10 @@ static void walk_getdents_process_dir(const char* dir,
     int flags = O_RDONLY | O_DIRECTORY;
     char buf[BUF_SIZE];
 
+#ifdef __linux__
     if (NO_ATIME)
         flags |= O_NOATIME;
+#endif
 
     /* TODO: may need to try these functions multiple times */
     mfu_file_t* mfu_file = *CURRENT_PFILE;
@@ -205,7 +207,17 @@ static void walk_getdents_process_dir(const char* dir,
     /* Read all directory entries */
     while (1) {
         /* execute system call to get block of directory entries */
-        int nread = syscall(SYS_getdents, mfu_file->fd, buf, (int) BUF_SIZE);
+        int nread;
+#ifdef __linux__
+        /* On Linux, call the raw getdents syscall as before */
+        nread = syscall(SYS_getdents, mfu_file->fd, buf, (int) BUF_SIZE);
+#else
+        /*
+         * On FreeBSD and other non-Linux systems, use the getdents(2)
+         * libc wrapper instead of the Linux-specific SYS_getdents.
+         */
+        nread = getdents(mfu_file->fd, (char *)buf, (size_t)BUF_SIZE);
+#endif
         if (nread == -1) {
             MFU_LOG(MFU_LOG_ERR, "syscall to getdents failed when reading `%s' (errno=%d %s)", dir, errno, strerror(errno));
             WALK_RESULT = -1;
@@ -767,7 +779,7 @@ void mfu_flist_stat(
         /* check whether we should skip this item */
         if (skip_fn != NULL && skip_fn(name, skip_args)) {
             /* skip this file, don't include it in new list */
-            MFU_LOG(MFU_LOG_INFO, "skip %s");
+            MFU_LOG(MFU_LOG_INFO, "skip %s", name);
             continue;
         }
 
