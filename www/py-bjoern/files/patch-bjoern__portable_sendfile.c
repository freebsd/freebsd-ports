See sendfile(2)

--- ./bjoern/portable_sendfile.c.orig	2012-07-23 14:46:30.000000000 +0000
+++ ./bjoern/portable_sendfile.c	2013-06-02 18:17:34.000000000 +0000
@@ -2,13 +2,16 @@
 
 #define SENDFILE_CHUNK_SIZE 16*1024
 
+#if defined(__APPLE__) || defined(__FreeBSD__)
+
+  #include <sys/types.h>
+  #include <sys/socket.h>
+  #include <sys/uio.h>
+
 #ifdef __APPLE__
 
   /* OS X */
 
-  #include <sys/socket.h>
-  #include <sys/types.h>
-
   ssize_t portable_sendfile(int out_fd, int in_fd) {
     off_t len = SENDFILE_CHUNK_SIZE;
     if(sendfile(in_fd, out_fd, 0, &len, NULL, 0) == -1)
@@ -18,6 +21,19 @@
 
 #else
 
+  /* FreeBSD */
+
+  ssize_t portable_sendfile(int out_fd, int in_fd) {
+    off_t len = SENDFILE_CHUNK_SIZE;
+    if(sendfile(in_fd, out_fd, 0, SENDFILE_CHUNK_SIZE, NULL, &len, 0) == -1)
+      return -1;
+    return len;
+  }
+
+#endif
+
+#else
+
   /* Linux */
 
   #include <sys/sendfile.h>
