--- src/clientbase.c.orig	2012-06-19 17:49:50.000000000 +0100
+++ src/clientbase.c	2012-06-19 17:50:29.000000000 +0100
@@ -160,7 +160,7 @@
 	} else {
 		/* server-side */
 		TRACE(TRACE_DEBUG,"saddr [%p] sa_family [%d] len [%d]", c->saddr, c->saddr->sa_family, c->saddr_len);
-		if ((serr = getnameinfo(c->saddr, c->saddr_len, client->dst_ip, NI_MAXHOST, client->dst_port, NI_MAXSERV, 
+		if ((serr = getnameinfo(c->saddr, c->saddr->sa_len, client->dst_ip, NI_MAXHOST, client->dst_port, NI_MAXSERV, 
 						NI_NUMERICHOST | NI_NUMERICSERV))) {
 			TRACE(TRACE_INFO, "getnameinfo::error [%s]", gai_strerror(serr));
 		}
@@ -168,7 +168,7 @@
 
 		/* client-side */
 		TRACE(TRACE_DEBUG,"caddr [%p] sa_family [%d] len [%d]", c->caddr, c->caddr->sa_family, c->caddr_len);
-		if ((serr = getnameinfo(c->caddr, c->caddr_len, client->src_ip, NI_MAXHOST, client->src_port, NI_MAXSERV,
+		if ((serr = getnameinfo(c->caddr, c->caddr->sa_len, client->src_ip, NI_MAXHOST, client->src_port, NI_MAXSERV,
 						NI_NUMERICHOST | NI_NUMERICSERV))) {
 			TRACE(TRACE_EMERG, "getnameinfo:error [%s]", gai_strerror(serr));
 		} 
