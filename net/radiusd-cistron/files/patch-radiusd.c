--- src/radiusd.c.orig	Wed Jul  2 11:39:03 2003
+++ src/radiusd.c	Fri Jul  9 15:57:46 2004
@@ -612,6 +612,7 @@
         if ((cl = client_find(authreq->ipaddr)) == NULL) {
                 log(L_ERR, "packet from unknown client/host: %s",
                         client_name(authreq->ipaddr));
+		authfree(authreq);
                 return -1;
         }
 	strNcpy(authreq->secret, cl->secret, sizeof(authreq->secret));
