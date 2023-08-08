--- src/clientbase.c.orig	2022-10-15 15:02:38 UTC
+++ src/clientbase.c
@@ -152,7 +152,7 @@ ClientBase_T * client_init(client_sock *c)
 		client->tx		= STDOUT_FILENO;
 	} else {
 		/* server-side */
-		if ((serr = getnameinfo(&c->saddr, c->saddr_len, client->dst_ip, 
+		if ((serr = getnameinfo(&c->saddr, c->saddr.sa_len, client->dst_ip, 
 						NI_MAXHOST, client->dst_port, 
 						NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV))) {
 			TRACE(TRACE_INFO, "getnameinfo::error [%s]", gai_strerror(serr));
@@ -160,7 +160,7 @@ ClientBase_T * client_init(client_sock *c)
 
 		/* client-side */
 		if (server_conf->resolveIP) {
-			if ((serr = getnameinfo(&c->caddr, c->caddr_len, client->clientname,
+			if ((serr = getnameinfo(&c->caddr, c->caddr.sa_len, client->clientname,
 						       	NI_MAXHOST-1, NULL, 0, NI_NAMEREQD))) {
 				TRACE(TRACE_INFO, "getnameinfo:error [%s]", gai_strerror(serr));
 			} 
@@ -171,7 +171,7 @@ ClientBase_T * client_init(client_sock *c)
 					client->clientname[0] ? client->clientname : "Lookup failed");
 		} else {
 
-			if ((serr = getnameinfo(&c->caddr, c->caddr_len, client->src_ip,
+			if ((serr = getnameinfo(&c->caddr, c->caddr.sa_len, client->src_ip,
 						       	NI_MAXHOST-1, client->src_port,
 						       	NI_MAXSERV-1, NI_NUMERICHOST | NI_NUMERICSERV))) {
 				TRACE(TRACE_INFO, "getnameinfo:error [%s]", gai_strerror(serr));
