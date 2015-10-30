--- evhtp.c.orig	2015-02-24 07:55:55 UTC
+++ evhtp.c
@@ -7,6 +7,7 @@
 #include <strings.h>
 #include <inttypes.h>
 #ifndef WIN32
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
@@ -3170,7 +3171,14 @@ evhtp_bind_sockaddr(evhtp_t * htp, struc
 
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
