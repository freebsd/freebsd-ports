--- snmp.c.orig	Tue Jul 20 17:51:25 2004
+++ snmp.c	Thu Nov  2 13:35:27 2006
@@ -1214,6 +1214,8 @@
 {
 	SESSION *sd = method->sd;
 	int reqid;
+	struct sockaddr_in *from;
+	char ipaddr[20];
 
 	/* sanity check */
 	if (!sd) return;
@@ -1225,7 +1227,13 @@
 		snmp_reply(errno, sd, 0);
 		return;
 	}
-
+	/* bind datagram socket to local source address */
+	from = (struct sockaddr_in *)&sd->me;
+	if ( from->sin_addr.s_addr != INADDR_ANY ) {		
+	    if( bind(sd->sock, &sd->me, sizeof(struct sockaddr) ) == -1 ) 
+		report(LOG_WARNING, "snmp_start : bind failed for %s: %s",
+		    	intoa(ipaddr,from->sin_addr), strerror(*(__error())) );
+	}
 	/* turn on non-blocking I/O */
 	if (set_socket_async(sd->sock, TRUE) < 0) {
 		snmp_reply(errno, sd, 0);
@@ -1290,7 +1298,7 @@
 	METHOD *method;
 {
 	SESSION template;
-	struct sockaddr_in *to;
+	struct sockaddr_in *to, *from;
 
 	dprintf(("snmp_init(%s/%s)\n", target->name, method->name));
 
@@ -1305,6 +1313,10 @@
 	to->sin_family = AF_INET;
 	to->sin_port = htons(method->rport);
 	to->sin_addr = method->address ? method->ip_addr : target->ip_addr;
+	from = (struct sockaddr_in *)&template.me;
+	bzero((char *)from, sizeof(struct sockaddr_in ));
+	from->sin_family = AF_INET;
+	from->sin_addr = target->ip_srcaddr;
 	template.timeout = method->timeout * 1000000L; /* make microseconds */
 	template.retries = method->retries;
 	template.send = snmp_send;
@@ -1334,6 +1346,7 @@
 	IPPROTO_UDP,	/* network protocol */
 	SNMPSERVER_PORT,/* server port */
 	0, 0,		/* timeout and retries undefined yet */
+        NULL,NULL,       /* when variables unused */
 	{ SNMP_VERSION_1,/* version number */
 	  0 },		 /* no parameter used */
 
