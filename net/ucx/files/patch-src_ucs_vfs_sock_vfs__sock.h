--- src/ucs/vfs/sock/vfs_sock.h.orig	2026-08-04 15:13:35 UTC
+++ src/ucs/vfs/sock/vfs_sock.h
@@ -15,7 +15,11 @@
 /* This header file defines socket operations for communicating between UCS
  * library and VFS daemon */
 
+#ifdef __FreeBSD__
+#define UCX_VFS_SOCK_DEFAULT_PATH "/tmp/ucx-%i/vfs.sock"
+#else
 #define UCX_VFS_SOCK_DEFAULT_PATH "/run/user/%i/ucx/vfs.sock"
+#endif
 
 
 /**
