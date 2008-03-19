=== lib/rpc/svc.c
==================================================================
--- lib/rpc/svc.c	(revision 1666)
+++ lib/rpc/svc.c	(local)
@@ -109,15 +109,17 @@
 	if (sock < FD_SETSIZE) {
 		xports[sock] = xprt;
 		FD_SET(sock, &svc_fdset);
+		if (sock > svc_maxfd)
+			svc_maxfd = sock;
 	}
 #else
 	if (sock < NOFILE) {
 		xports[sock] = xprt;
 		svc_fds |= (1 << sock);
+		if (sock > svc_maxfd)
+			svc_maxfd = sock;
 	}
 #endif /* def FD_SETSIZE */
-	if (sock > svc_maxfd)
-		svc_maxfd = sock;
 }
 
 /*
