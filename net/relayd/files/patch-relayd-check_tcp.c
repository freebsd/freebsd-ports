--- relayd/check_tcp.c.orig	2011-01-15 00:27:09.011450590 +0100
+++ relayd/check_tcp.c	2011-01-15 00:42:05.271822942 +0100
@@ -50,11 +50,10 @@
 check_tcp(struct ctl_tcp_event *cte)
 {
 	int			 s;
-	int			 type;
 	socklen_t		 len;
 	struct timeval		 tv;
 	struct linger		 lng;
-	int			 he = HCE_TCP_CONNECT_ERROR;
+	int			 he = HCE_TCP_SOCKET_OPTION;
 
 	switch (cte->host->conf.ss.ss_family) {
 	case AF_INET:
@@ -69,17 +68,18 @@
 
 	len = ((struct sockaddr *)&cte->host->conf.ss)->sa_len;
 
-	if ((s = socket(cte->host->conf.ss.ss_family, SOCK_STREAM, 0)) == -1)
+	if ((s = socket(cte->host->conf.ss.ss_family, SOCK_STREAM, 0)) == -1) {
+		if (errno == EMFILE || errno == ENFILE)
+			he = HCE_TCP_SOCKET_LIMIT;
+		else
+			he = HCE_TCP_SOCKET_ERROR;
 		goto bad;
+	}
 
 	bzero(&lng, sizeof(lng));
 	if (setsockopt(s, SOL_SOCKET, SO_LINGER, &lng, sizeof(lng)) == -1)
 		goto bad;
 
-	type = 1;
-	if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &type, sizeof(type)) == -1)
-		goto bad;
-
 	if (cte->host->conf.ttl > 0) {
 		if (setsockopt(s, IPPROTO_IP, IP_TTL,
 		    &cte->host->conf.ttl, sizeof(int)) == -1)
@@ -99,6 +99,7 @@
 
 	cte->buf = NULL;
 	cte->host->up = HOST_UP;
+	event_del(&cte->ev);
 	event_set(&cte->ev, s, EV_TIMEOUT|EV_WRITE, tcp_write, cte);
 	event_add(&cte->ev, &tv);
 	return;
