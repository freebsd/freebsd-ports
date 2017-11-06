--- src/clientbase.c.orig	2015-01-25 10:20:50 UTC
+++ src/clientbase.c
@@ -151,7 +151,7 @@ ClientBase_T * client_init(client_sock *
 		client->tx		= STDOUT_FILENO;
 	} else {
 		/* server-side */
-		if ((serr = getnameinfo(&c->saddr, c->saddr_len, client->dst_ip, 
+		if ((serr = getnameinfo(&c->saddr, c->saddr.sa_len, client->dst_ip, 
 						NI_MAXHOST, client->dst_port, 
 						NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV))) {
 			TRACE(TRACE_INFO, "getnameinfo::error [%s]", gai_strerror(serr));
@@ -159,7 +159,7 @@ ClientBase_T * client_init(client_sock *
 
 		/* client-side */
 		if (server_conf->resolveIP) {
-			if ((serr = getnameinfo(&c->caddr, c->caddr_len, client->clientname,
+			if ((serr = getnameinfo(&c->caddr, c->caddr.sa_len, client->clientname,
 						       	NI_MAXHOST-1, NULL, 0, NI_NAMEREQD))) {
 				TRACE(TRACE_INFO, "getnameinfo:error [%s]", gai_strerror(serr));
 			} 
@@ -170,7 +170,7 @@ ClientBase_T * client_init(client_sock *
 					client->clientname[0] ? client->clientname : "Lookup failed");
 		} else {
 
-			if ((serr = getnameinfo(&c->caddr, c->caddr_len, client->src_ip,
+			if ((serr = getnameinfo(&c->caddr, c->caddr.sa_len, client->src_ip,
 						       	NI_MAXHOST-1, client->src_port,
 						       	NI_MAXSERV-1, NI_NUMERICHOST | NI_NUMERICSERV))) {
 				TRACE(TRACE_INFO, "getnameinfo:error [%s]", gai_strerror(serr));
