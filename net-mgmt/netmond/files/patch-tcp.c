--- tcp.c.orig	Wed Sep 17 12:55:52 2003
+++ tcp.c	Thu Nov  2 13:35:27 2006
@@ -16,6 +16,7 @@
 #include <netinet/in.h>
 #include <stdio.h>
 #include <string.h>
+#include <signal.h>
 #include <unistd.h>
 #include <syslog.h>
 #include <errno.h>
@@ -30,12 +31,10 @@
 
 extern int errno;
 
-static void tcp_close __P((int, SESSION *, int));
-
 /*
  * Check to see if an TCP connection established at this session.
  */
-static int
+int
 tcp_connect(sd)
 	SESSION *sd;
 {
@@ -89,7 +88,7 @@
 /*
  * Send the data through TCP session.
  */
-static int
+int
 tcp_send(sd, request)
 	SESSION *sd;
 	REQUEST *request;
@@ -191,7 +190,7 @@
 /*
  * Receive data through TCP session.
  */
-static int
+int
 tcp_recv(sd)
 	SESSION *sd;
 {
@@ -319,6 +318,8 @@
 {
 	SESSION *sd = method->sd;
 	int tmpval;
+	struct sockaddr_in *from;
+	char ipaddr[20];
 
 	/* sanity check */
 	if (!sd) return;
@@ -330,17 +331,13 @@
 		tcp_close(errno, sd, 0);
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
@@ -354,6 +351,13 @@
 			tcp_close(EAGAIN, sd, 0);
 			return;
 		}
+	} else {
+	    /* bind  socket to local source address */
+	    if ( from->sin_addr.s_addr != INADDR_ANY ) {		
+		if( bind(sd->sock, &sd->me, sizeof(struct sockaddr) ) == -1 ) 
+		    report(LOG_WARNING, "tcp_start : bind failed for %s: %s",
+    	        	intoa(ipaddr,from->sin_addr), strerror(*(__error())) );
+	    }	
 	}
 
 	/* turn on non-blocking I/O before connecting */
@@ -378,7 +382,7 @@
 	}
 }
 
-static void
+void
 tcp_close(op, sd, reqid)
 	int op;
 	SESSION *sd;
@@ -414,6 +418,7 @@
 	dump_var_list(target->var_list);
 
 	tcp_stop(method);
+	if ((method->sd)->pid > 0) { kill((method->sd)->pid, SIGTERM); (method->sd)->pid=-1; }
 
 	method_finished(target, method, diag, !op);
 }
@@ -424,7 +429,7 @@
 	METHOD *method;
 {
 	SESSION template;
-	struct sockaddr_in *to;
+	struct sockaddr_in *to, *from;
 
 	dprintf(("tcp_init(%s/%s)\n", target->name, method->name));
 
@@ -435,10 +440,15 @@
 	template.owner = target;
 	template.method = method;
 	template.sock = -1;	/* not yet opened */
+	template.pid = -1;	
 	to = (struct sockaddr_in *)&template.peer;
 	to->sin_family = AF_INET;
 	to->sin_port = htons(method->rport);
 	to->sin_addr = method->address ? method->ip_addr : target->ip_addr;
+	from = (struct sockaddr_in *)&template.me;
+	bzero((char *)from, sizeof(struct sockaddr_in));
+	from->sin_family = AF_INET;
+	from->sin_addr = target->ip_srcaddr;
 	template.timeout = method->timeout * 1000000L; /* make microseconds */
 	template.retries = method->retries;
 	template.connect = tcp_connect;
