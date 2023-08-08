--- src/close_fds.c.orig	2023-02-28 02:39:11 UTC
+++ src/close_fds.c
@@ -22,6 +22,12 @@
 
 #include <sys/stat.h>
 
+#ifdef __FreeBSD__
+#define OPEN_FILES_DIR "/dev/fd"
+#else
+#define OPEN_FILES_DIR "/proc/self/fd"
+#endif
+
 static int open_files_max_fd;
 static fd_set *open_files_set;
 
@@ -31,7 +37,7 @@ static void __attribute__((constructor)) init()
 	ssize_t size = 0;
 	DIR *d;
 
-	d = opendir("/proc/self/fd");
+	d = opendir(OPEN_FILES_DIR);
 	if (!d)
 		return;
 
@@ -85,7 +91,7 @@ void close_all_fds_ge_than(int firstfd)
 	struct dirent *ent;
 	DIR *d;
 
-	d = opendir("/proc/self/fd");
+	d = opendir(OPEN_FILES_DIR);
 	if (!d)
 		return;
 
