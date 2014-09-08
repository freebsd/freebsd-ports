--- evhtp.c.orig	2014-03-23 07:50:50.000000000 -0400
+++ evhtp.c	2014-08-28 09:08:40.970619326 -0400
@@ -6,6 +6,10 @@
 #include <signal.h>
 #include <strings.h>
 #include <inttypes.h>
+#ifdef SO_ACCEPTFILTER 
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
 #ifndef WIN32
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -2740,7 +2744,14 @@
 
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
