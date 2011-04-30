--- content/browser/renderer_host/render_sandbox_host_linux.cc.orig	2011-04-16 11:01:10.000000000 +0300
+++ content/browser/renderer_host/render_sandbox_host_linux.cc	2011-04-27 00:17:53.236984447 +0300
@@ -13,6 +13,9 @@
 #include <sys/socket.h>
 #include <sys/poll.h>
 #include <time.h>
+#if defined(OS_FREEBSD)
+#include <sys/param.h>
+#endif
 
 #include <vector>
 
@@ -665,7 +668,11 @@
   // inherit some sockets. With PF_UNIX+SOCK_DGRAM, it can call sendmsg to send
   // a datagram to any (abstract) socket on the same system. With
   // SOCK_SEQPACKET, this is prevented.
+#if defined(OS_FREEBSD) && (__FreeBSD_version < 900030)
+  CHECK(socketpair(AF_UNIX, SOCK_DGRAM, 0, fds) == 0);
+#else
   CHECK(socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds) == 0);
+#endif
 
   renderer_socket_ = fds[0];
   const int browser_socket = fds[1];
