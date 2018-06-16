--- deps/libneon/src/ne_socket.c.orig	2018-06-16 07:30:42 UTC
+++ deps/libneon/src/ne_socket.c
@@ -31,9 +31,9 @@
 #include <sys/time.h>
 #endif
 #include <sys/stat.h>
-#ifdef HAVE_SYS_SOCKET_H
+//#ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
-#endif
+//#endif
 
 #ifdef __linux__
 #include <sys/ioctl.h>
