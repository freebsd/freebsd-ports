--- ./xbmc/network/Socket.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/network/Socket.h	2012-01-02 10:14:38.000000000 +0100
@@ -30,6 +30,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #ifdef _LINUX
 typedef int SOCKET;
 #endif
