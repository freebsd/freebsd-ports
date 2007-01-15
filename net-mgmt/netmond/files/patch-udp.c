--- udp.c.orig	Sat Aug  2 11:40:56 2003
+++ udp.c	Thu Nov  2 13:35:27 2006
@@ -197,6 +197,8 @@
 {
 	SESSION *sd = method->sd;
 	int tmpval;
+	struct sockaddr_in *from;
+	char ipaddr[20];
 
 	/* sanity check */
 	if (!sd) return;
@@ -208,17 +210,13 @@
 		udp_close(errno, sd, 0);
 		return;
 	}
-
+	from = (struct sockaddr_in *)&sd->me;
 	/* allocate local port if required */
 	if (method->lport_min) {
-		struct sockaddr_in sin;
-
-		sin.sin_family = AF_INET;
-		sin.sin_addr.s_addr = htonl(INADDR_ANY);
 		tmpval = method->lport_min;
 		do {
-			sin.sin_port = htons((u_short)tmpval);
-			if (!bind(sd->sock, (struct sockaddr *)&sin, sizeof(sin))) {
+			from->sin_port = htons((u_short)tmpval);
+			if (!bind(sd->sock, &sd->me, sizeof(struct sockaddr))) {
 				tmpval = 0;
 				break;
 			}
@@ -232,6 +230,13 @@
 			udp_close(EAGAIN, sd, 0);
 			return;
 		}
+	} else {
+	    /* bind socket to local source address */
+	    if ( from->sin_addr.s_addr != INADDR_ANY ) {		
+		if( bind(sd->sock, &sd->me, sizeof(struct sockaddr) ) == -1 ) 
+		    report(LOG_WARNING, "udp_start : bind failed for %s: %s",
+		    	intoa(ipaddr,from->sin_addr), strerror(*(__error())) );
+	    }
 	}
 
 	/* turn on non-blocking I/O */
@@ -298,7 +303,7 @@
 	METHOD *method;
 {
 	SESSION template;
-	struct sockaddr_in *to;
+	struct sockaddr_in *to, *from;
 
 	dprintf(("udp_init(%s/%s)\n", target->name, method->name));
 
@@ -313,6 +318,10 @@
 	to->sin_family = AF_INET;
 	to->sin_port = htons(method->rport);
 	to->sin_addr = method->address ? method->ip_addr : target->ip_addr;
+	from = (struct sockaddr_in *)&template.me;
+	bzero((char *)from, sizeof(struct sockaddr_in));
+	from->sin_family = AF_INET;
+	from->sin_addr = target->ip_srcaddr;
 	template.timeout = method->timeout * 1000000L; /* make microseconds */
 	template.retries = method->retries;
 	template.send = udp_send;
