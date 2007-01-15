--- router.c.orig	Mon Aug 25 16:07:07 2003
+++ router.c	Thu Dec 28 13:31:06 2006
@@ -309,6 +309,7 @@
 	for (group_ref = proto->ns_acl; group_ref; group_ref = group_ref->next)
 		add_group_ref_copy(&iface->ns_acl, group_ref);
 
+	iface->ignore_state = proto->ignore_state;
         if (last)
                 last->next = iface;
         else    object->interface = iface;
@@ -2214,6 +2215,8 @@
 	METHOD *method;
 {
 	SESSION *sd = method->sd;
+	struct sockaddr_in *from;
+	char ipaddr[20];
 
 	/* sanity check */
 	if (!sd) {
@@ -2229,7 +2232,13 @@
 		router_reply(errno, sd, 0);
 		return;
 	}
-
+	/* bind socket to local source address */
+	from = (struct sockaddr_in *)&sd->me;
+	if ( from->sin_addr.s_addr != INADDR_ANY ) {		
+	    if( bind(sd->sock, &sd->me, sizeof(struct sockaddr) ) == -1 ) 
+		report(LOG_WARNING, "router_start : bind failed for %s: %s",
+		    	intoa(ipaddr,from->sin_addr), strerror(*(__error())) );
+	}
 	/* turn on non-blocking I/O */
 	if (set_socket_async(sd->sock, TRUE) < 0) {
 		router_reply(errno, sd, 0);
@@ -2306,7 +2315,7 @@
 	METHOD *method;
 {
 	SESSION template;
-	struct sockaddr_in *to;
+	struct sockaddr_in *to, *from;
 
 	dprintf(("router_init(%s/%s)\n", target->name, method->name));
 
@@ -2321,6 +2330,10 @@
 	to->sin_family = AF_INET;
 	to->sin_port = htons(method->rport);
 	to->sin_addr = method->address ? method->ip_addr : target->ip_addr;
+	from = (struct sockaddr_in *)&template.me;
+	bzero((char *)from, sizeof (struct sockaddr_in));
+	from->sin_family = AF_INET;
+	from->sin_addr = target->ip_srcaddr;
 	template.timeout = method->timeout * 1000000L; /* make microseconds */
 	template.retries = method->retries;
 	template.send = snmp_send;
@@ -2359,6 +2372,7 @@
 	IPPROTO_UDP,	/* network protocol */
 	SNMPSERVER_PORT,/* server port */
 	0, 0,		/* timeout and retries undefined yet */
+        NULL,NULL,       /* when variables unused */
 	{ SNMP_VERSION_1, /* version number */
 	  BATCH_DEFAULT },/* batch value */
 
