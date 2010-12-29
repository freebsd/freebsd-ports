--- ./xbmc/lib/libhts/net_posix.c.orig	2010-02-15 06:06:37.000000000 +0100
+++ ./xbmc/lib/libhts/net_posix.c	2010-12-01 12:17:34.312321908 +0100
@@ -17,12 +17,14 @@
  */
 
 #include <netdb.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 /* Needed on Mac OS/X */
 #ifndef SOL_TCP
 #define SOL_TCP IPPROTO_TCP
 #endif
+#if defined(__APPLE__)
 #include "OSXGNUReplacements.h"
+#endif
 #else
 #include <sys/epoll.h>
 #endif
@@ -41,6 +43,10 @@
 
 #include "net.h"
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#endif
+
 
 /**
  *
