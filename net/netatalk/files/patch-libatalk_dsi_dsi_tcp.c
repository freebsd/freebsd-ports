--- libatalk/dsi/dsi_tcp.c.orig	2010-07-02 10:48:44.000000000 -0400
+++ libatalk/dsi/dsi_tcp.c	2010-08-15 17:49:41.000000000 -0400
@@ -277,19 +277,22 @@ int dsi_tcp_init(DSI *dsi, const char *h
 {
     int                ret;
     int                flag;
+    int                on;
     struct addrinfo    hints, *servinfo, *p;
 
     dsi->protocol = DSI_TCPIP;
 
     /* Prepare hint for getaddrinfo */
     memset(&hints, 0, sizeof hints);
-    hints.ai_family = AF_UNSPEC;
     hints.ai_socktype = SOCK_STREAM;
     hints.ai_flags = AI_NUMERICSERV;
-    if ( ! address)
+    if ( ! address) {
         hints.ai_flags |= AI_PASSIVE;
-    else
+	hints.ai_family = AF_INET6;
+    } else {
         hints.ai_flags |= AI_NUMERICHOST;
+	hints.ai_family = AF_UNSPEC;
+    }
 
     if ((ret = getaddrinfo(address ? address : NULL, port ? port : "548", &hints, &servinfo)) != 0) {
         LOG(log_error, logtype_dsi, "dsi_tcp_init: getaddrinfo: %s\n", gai_strerror(ret));
@@ -316,6 +319,10 @@ int dsi_tcp_init(DSI *dsi, const char *h
             flag = 1;
             setsockopt(dsi->serversock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
 #endif
+#ifdef IPV6_BINDV6ONLY
+	    on = 0;
+	    setsockopt(dsi->serversock, IPPROTO_IPV6, IPV6_BINDV6ONLY, (char *)&on, sizeof (on));
+#endif
 
 #ifdef USE_TCP_NODELAY
 #ifndef SOL_TCP
