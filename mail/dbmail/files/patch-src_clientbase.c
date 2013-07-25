--- src/clientbase.c.orig	2013-07-22 20:03:36.000000000 +0100
+++ src/clientbase.c	2013-07-23 13:14:56.000000000 +0100
@@ -159,14 +159,14 @@
 		client->tx		= STDOUT_FILENO;
 	} else {
 		/* server-side */
-		if ((serr = getnameinfo(c->saddr, c->saddr_len, client->dst_ip, NI_MAXHOST, client->dst_port, NI_MAXSERV, 
+		if ((serr = getnameinfo(c->saddr, c->saddr->sa_len, client->dst_ip, NI_MAXHOST, client->dst_port, NI_MAXSERV, 
 						NI_NUMERICHOST | NI_NUMERICSERV))) {
 			TRACE(TRACE_INFO, "getnameinfo::error [%s]", gai_strerror(serr));
 		}
 
 		/* client-side */
 		if (server_conf->resolveIP) {
-			if ((serr = getnameinfo(c->caddr, c->caddr_len, client->clientname, NI_MAXHOST, NULL, 0,
+			if ((serr = getnameinfo(c->caddr, c->caddr->sa_len, client->clientname, NI_MAXHOST, NULL, 0,
 						       	NI_NAMEREQD))) {
 				TRACE(TRACE_INFO, "getnameinfo:error [%s]", gai_strerror(serr));
 			} 
@@ -177,7 +177,7 @@
 					client->clientname[0] ? client->clientname : "Lookup failed");
 		} else {
 
-			if ((serr = getnameinfo(c->caddr, c->caddr_len, client->src_ip, NI_MAXHOST, client->src_port,
+			if ((serr = getnameinfo(c->caddr, c->caddr->sa_len, client->src_ip, NI_MAXHOST, client->src_port,
 						       	NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV))) {
 				TRACE(TRACE_INFO, "getnameinfo:error [%s]", gai_strerror(serr));
 			} 
