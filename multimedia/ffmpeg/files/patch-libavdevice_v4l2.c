- ioctl() prototype on BSDs follows Version 7 AT&T UNIX

--- libavdevice/v4l2.c.orig	2019-04-21 04:37:17 UTC
+++ libavdevice/v4l2.c
@@ -95,10 +95,10 @@ struct video_data {
     int (*open_f)(const char *file, int oflag, ...);
     int (*close_f)(int fd);
     int (*dup_f)(int fd);
-#ifdef __GLIBC__
-    int (*ioctl_f)(int fd, unsigned long int request, ...);
-#else
+#if defined(__sun) || defined(__BIONIC__) || defined(__musl__) /* POSIX-like */
     int (*ioctl_f)(int fd, int request, ...);
+#else
+    int (*ioctl_f)(int fd, unsigned long int request, ...);
 #endif
     ssize_t (*read_f)(int fd, void *buffer, size_t n);
     void *(*mmap_f)(void *start, size_t length, int prot, int flags, int fd, int64_t offset);
