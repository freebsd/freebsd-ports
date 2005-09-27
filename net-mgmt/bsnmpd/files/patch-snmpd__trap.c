--- snmpd/trap.c.orig	Wed Sep 21 11:42:50 2005
+++ snmpd/trap.c	Wed Sep 21 11:42:06 2005
@@ -111,7 +111,7 @@
 
 	if (connect(t->socket, (struct sockaddr *)&sa, sa.sin_len) == -1) {
 		syslog(LOG_ERR, "connect(%s,%u): %m",
-		    inet_ntoa(sa.sin_addr), ntohl(sa.sin_port));
+		    inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
 		(void)close(t->socket);
 		free(t);
 		return (SNMP_ERR_GENERR);
