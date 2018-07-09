--- deps/libneon/src/ne_socket.c.orig	2018-06-15 09:35:23 UTC
+++ deps/libneon/src/ne_socket.c
@@ -34,9 +34,9 @@
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
