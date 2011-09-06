--- lib/rpc/clnt_tcp.c.orig	2011-09-06 02:05:14.000000000 +0000
+++ lib/rpc/clnt_tcp.c	2011-09-06 02:10:30.000000000 +0000
@@ -187,9 +187,16 @@
 	ct->ct_sock = *sockp;
 	ct->ct_wait.tv_usec = 0;
 	ct->ct_waitset = FALSE;
-	if (raddr == NULL)
-	    memset(&ct->ct_addr, 0, sizeof(ct->ct_addr));
+	if (raddr == NULL) {
+	/* Get the remote address from the socket, if it's IPv4. */
+	struct sockaddr_in sin;
+	socklen_t len = sizeof(sin);
+	int ret = getpeername(ct->ct_sock, (struct sockaddr *)&sin, &len);
+	if (ret == 0 && len == sizeof(sin) && sin.sin_family == AF_INET)
+      ct->ct_addr = sin;
 	else
+      memset(&ct->ct_addr, 0, sizeof(ct->ct_addr));
+    } else
 	    ct->ct_addr = *raddr;
 
 	/*
