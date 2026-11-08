--- src/tools/vfs/vfs_main.c.orig	2026-08-04 01:14:50 UTC
+++ src/tools/vfs/vfs_main.c
@@ -37,7 +37,7 @@ static struct sockaddr_un g_sockaddr;
 static struct sockaddr_un g_sockaddr;
 
 
-static int vfs_run_fusermount(char **extra_argv)
+static int vfs_run_fusermount(const char *program, char **extra_argv, int add_quiet_option)
 {
     char command[128];
     pid_t child_pid;
@@ -48,8 +48,8 @@ static int vfs_run_fusermount(char **extra_argv)
     int i, argc;
 
     argc         = 0;
-    argv[argc++] = VFS_FUSE_MOUNT_PROG;
-    if (!g_opts.verbose) {
+    argv[argc++] = (char*)program;
+    if (add_quiet_option && !g_opts.verbose) {
         argv[argc++] = "-q";
     }
     while (*extra_argv != NULL) {
@@ -223,7 +223,11 @@ int vfs_unmount(int pid)
 int vfs_unmount(int pid)
 {
     char *mountpoint;
+#ifdef __FreeBSD__
+    char *argv[2];
+#else
     char *argv[5];
+#endif
     int ret;
 
     /* Unmount FUSE file system */
@@ -233,12 +237,19 @@ int vfs_unmount(int pid)
         goto out;
     }
 
+#ifdef __FreeBSD__
+    argv[0] = mountpoint;
+    argv[1] = NULL;
+
+    ret = vfs_run_fusermount(VFS_FUSE_UNMOUNT_PROG, argv, 0);
+#else
     argv[0] = "-u";
     argv[1] = "-z";
     argv[2] = "--";
     argv[3] = mountpoint;
     argv[4] = NULL;
-    ret     = vfs_run_fusermount(argv);
+    ret     = vfs_run_fusermount(VFS_FUSE_UNMOUNT_PROG, argv, 1);
+#endif
     if (ret < 0) {
         goto out_free_mountpoint;
     }
@@ -505,8 +516,18 @@ static int vfs_test_fuse()
 
 static int vfs_test_fuse()
 {
+#ifdef __FreeBSD__
+    if (access(VFS_FUSE_MOUNT_PROG, X_OK) < 0) {
+        vfs_error("cannot execute '%s': %m", VFS_FUSE_MOUNT_PROG);
+        return -errno;
+    }
+
+    return 0;
+#else
     char *argv[] = {"-V", NULL};
-    return vfs_run_fusermount(argv);
+
+    return vfs_run_fusermount(VFS_FUSE_MOUNT_PROG, argv, 0);
+#endif
 }
 
 int main(int argc, char **argv)
