--- ping.c.orig	Fri Aug 22 11:07:53 2003
+++ ping.c	Thu Dec 28 13:31:06 2006
@@ -352,7 +352,8 @@
 	dprintf(("check_netpath(%s)\n", target->name));
 
 	for (nexthop = target->nexthop; nexthop; nexthop = nexthop->next) {
-		if ((nexthop->target && nexthop->target->state != STATE_UP) ||
+		if ((nexthop->target && nexthop->target->state == STATE_UNKNOWN) ||
+		    (nexthop->target && nexthop->target->state == STATE_DOWN) ||
 		    (nexthop->interface && nexthop->interface->state != STATE_UP))
 			return 0;
 	}
@@ -368,6 +369,7 @@
 	u_char buf[MAX_PACKETSZ];
 	struct ip *ip;
 	struct icmp *icmp;
+	struct sockaddr_in *from = (struct sockaddr_in *)&sd->me;
 	struct sockaddr_in *to = (struct sockaddr_in *)&sd->peer;
 	int header_len = sizeof(struct ip);
 	int total_len = method->rport ? method->rport : MIN_PACKETSZ;
@@ -400,7 +402,7 @@
 #endif
 	ip->ip_ttl = IPDEFTTL;
 	ip->ip_p = IPPROTO_ICMP;
-	/* ip->ip_src <-- filled by kernel (hopefulness) */
+	ip->ip_src = from->sin_addr; /* replaced by kernel if=INADDR_ANY (hopefulness) */
 	ip->ip_dst = to->sin_addr;
 
 	if (rr_opt) { /* IP Option: Record Route */
@@ -423,6 +425,7 @@
 	memcpy(icmp->icmp_data, &sd->buf, sizeof(TIMEVAL *));
 
 	icmp->icmp_cksum = in_cksum((u_short *)icmp, total_len - header_len);
+
 #ifdef	NO_ICMP_ERRORS
 	total_len = send(sd->sock, (char *)buf, total_len, 0);
 #else
@@ -600,6 +603,8 @@
 {
 	SESSION *sd = method->sd;
 	int tmpval;
+	char	ipaddr[20];
+	struct	sockaddr_in	*from;
 
 	/* sanity check */
 	if (!sd) return;
@@ -616,6 +621,13 @@
 		echo_reply(errno, sd, 0);
 		return;
 	}
+	/* bind RAW socket to local source address */
+	from = (struct sockaddr_in *)&sd->me;
+	if ( from->sin_addr.s_addr != INADDR_ANY ) {		
+	    if( bind(sd->sock, &sd->me, sizeof(struct sockaddr) ) == -1 ) 
+		report(LOG_WARNING, "echo_start : bind failed for %s: %s",
+		    	intoa(ipaddr,from->sin_addr), strerror(*(__error())) );
+	}
 #ifdef	SO_BSDCOMPAT
 	/* The following option is only necessary on Linux machines because
 	 * they have the unusual behavior of returning some ICMP errors to
@@ -701,7 +713,12 @@
 				if (sd->pkt_recv > 1) msec /= (double)sd->pkt_recv;
 				sprintf(buf, "%g", msec);
 				diag = buf;
-			} else	diag = "0.000";
+			    if ( msec >= 10 ) {
+				sprintf(buf, "%d", (int)msec);
+			    } else {
+				sprintf(buf, "%g", msec);
+			    }
+			} else	diag = "0.0";
 		} else {
 			op = -1;
 			diag = icmp_error(sd->data_int);
@@ -740,8 +757,9 @@
 	METHOD *method;
 {
 	SESSION template;
-	struct sockaddr_in *to;
+	struct sockaddr_in *to, *from;
 	char varname[100];
+	char ipaddr[20];
 
 	dprintf(("echo_init(%s/%s)\n", target->name, method->name));
 
@@ -758,6 +776,9 @@
 	to = (struct sockaddr_in *)&template.peer;
 	to->sin_family = AF_INET;
 	to->sin_addr = method->address ? method->ip_addr : target->ip_addr;
+	from = (struct sockaddr_in *)&template.me;
+	from->sin_family = AF_INET;
+	from->sin_addr = target->ip_srcaddr;
 	template.timeout = method->timeout * 1000000L; /* make microseconds */
 	template.retries = method->retries;
 	template.send = echo_send;
@@ -798,6 +819,7 @@
 	IPPROTO_ICMP,	/* network protocol */
 	0,		/* no packet size for built-in method */
 	0, 0,		/* timeout and retries undefined yet */
+	NULL,NULL,	/* when variables unused */
 	{ 1, 1 },	/* send/expect packet counter */
 
 	/* Non-initialized data */
