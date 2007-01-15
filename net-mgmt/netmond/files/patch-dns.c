--- dns.c.orig	Mon Aug 25 18:19:04 2003
+++ dns.c	Thu Nov  2 13:35:27 2006
@@ -149,6 +149,8 @@
 {
 	SESSION *sd = method->sd;
 	int reqid;
+	struct sockaddr_in *from;
+	char ipaddr[20];
 
 	/* sanity check */
 	if (!sd) return;
@@ -161,6 +163,14 @@
 		return;
 	}
 
+	/* bind  socket to local source address */
+
+	from = (struct sockaddr_in *)&sd->me;
+	if ( from->sin_addr.s_addr != INADDR_ANY ) {		
+	    if( bind(sd->sock, &sd->me, sizeof(struct sockaddr) ) == -1 ) 
+		report(LOG_WARNING, "dns_start : bind failed for %s: %s",
+		    	intoa(ipaddr,from->sin_addr), strerror(*(__error())) );
+	}
 	/* turn on non-blocking I/O */
 	if (set_socket_async(sd->sock, TRUE) < 0) {
 		dns_reply(errno, sd, 0);
@@ -288,7 +298,7 @@
 	METHOD *method;
 {
 	SESSION template;
-	struct sockaddr_in *to;
+	struct sockaddr_in *to, *from;
 
 	dprintf(("dns_init(%s/%s)\n", target->name, method->name));
 
@@ -303,6 +313,10 @@
 	to->sin_family = AF_INET;
 	to->sin_port = htons(method->rport);
 	to->sin_addr = method->address ? method->ip_addr : target->ip_addr;
+	from = (struct sockaddr_in *)&template.me;
+	bzero((char *)from, sizeof(struct sockaddr_in));
+	from->sin_family = AF_INET;
+	from->sin_addr = target->ip_srcaddr;
 	template.timeout = method->timeout * 1000000L; /* make microseconds */
 	template.retries = method->retries;
 	template.send = dns_send;
@@ -332,6 +346,7 @@
 	IPPROTO_UDP,	/* network protocol */
 	NAMESERVER_PORT, /* server port */
 	0, 0,		/* timeout and retries undefined yet */
+        NULL,NULL,       /* when variables unused */
 	{ 0, 0 },	/* no parameters used */
 
 	/* Non-initialized data */
