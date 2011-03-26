--- a/cxsocket.c
+++ b/cxsocket.c
@@ -35,7 +35,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 # include <sys/sendfile.h>
 #endif
 #include <netinet/tcp.h>
@@ -191,7 +191,7 @@ bool cxSocket::set_multicast(int ttl)
 
 bool cxSocket::set_cork(bool state)
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   return false;
 #else
   int iCork = state ? 1 : 0;
