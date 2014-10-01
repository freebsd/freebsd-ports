--- evhtp.c.orig	2014-03-23 11:50:50.000000000 +0000
+++ evhtp.c	2014-09-13 12:37:11.000000000 +0000
@@ -7,6 +7,7 @@
 #include <strings.h>
 #include <inttypes.h>
 #ifndef WIN32
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
@@ -2740,7 +2741,14 @@
 
         sock = evconnlistener_get_fd(htp->server);
 
+#ifdef TCP_DEFER_ACCEPT
         setsockopt(sock, IPPROTO_TCP, TCP_DEFER_ACCEPT, &one, (ev_socklen_t)sizeof(one));
+#elif SO_ACCEPTFILTER
+        struct accept_filter_arg afa;
+        bzero(&afa, sizeof(afa));
+        strcpy(afa.af_name, "httpready");
+        setsockopt(sock, SOL_SOCKET, SO_ACCEPTFILTER, &afa, sizeof(afa));
+#endif
         setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &one, (ev_socklen_t)sizeof(one));
     }
 #endif
