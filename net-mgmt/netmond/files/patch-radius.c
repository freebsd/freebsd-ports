--- radius.c.orig	Mon Aug 25 18:20:03 2003
+++ radius.c	Mon Nov 13 16:58:49 2006
@@ -33,7 +33,7 @@
  * RADIUS specification according to RFC2138.
  */
 
-#define	RADIUSSERVER_PORT	1645	/* 1812 suggested */
+#define	RADIUSSERVER_PORT	1812	/* 1812 suggested */
 #define	HEADER_LEN		20
 #define	MIN_PACKETSZ		HEADER_LEN
 #define	MAX_PACKETSZ		4096
@@ -208,6 +208,8 @@
 {
 	SESSION *sd = method->sd;
 	int reqid;
+	struct sockaddr_in *from;
+	char ipaddr[20];
 
 	/* sanity check */
 	if (!sd) return;
@@ -220,6 +222,13 @@
 		return;
 	}
 
+	/* bind  socket to local source address */
+	from = (struct sockaddr_in *)&sd->me;
+	if ( from->sin_addr.s_addr != INADDR_ANY ) {		
+	    if( bind(sd->sock, &sd->me, sizeof(struct sockaddr) ) == -1 ) 
+		report(LOG_WARNING, "radius_start : bind failed for %s: %s",
+		    intoa(ipaddr,from->sin_addr), strerror(*(__error())) );
+	}	
 	/* turn on non-blocking I/O */
 	if (set_socket_async(sd->sock, TRUE) < 0) {
 		radius_reply(errno, sd, 0);
@@ -311,7 +320,7 @@
 	METHOD *method;
 {
 	SESSION template;
-	struct sockaddr_in *to;
+	struct sockaddr_in *to, *from;
 
 	dprintf(("radius_init(%s/%s)\n", target->name, method->name));
 
@@ -326,6 +335,10 @@
 	to->sin_family = AF_INET;
 	to->sin_port = htons(method->rport);
 	to->sin_addr = method->address ? method->ip_addr : target->ip_addr;
+	from = (struct sockaddr_in *)&template.me;
+	bzero((char *)from, sizeof(struct sockaddr_in));
+	from->sin_family = AF_INET;
+	from->sin_addr = target->ip_srcaddr;
 	template.timeout = method->timeout * 1000000L; /* make microseconds */
 	template.retries = method->retries;
 	template.send = radius_send;
@@ -355,6 +368,7 @@
 	IPPROTO_UDP,	/* network protocol */
 	RADIUSSERVER_PORT, /* server port */
 	0, 0,		/* timeout and retries undefined yet */
+        NULL,NULL,       /* when variables unused */
 	{ 0, 0 },	/* no parameters used */
 
 	/* Non-initialized data */
