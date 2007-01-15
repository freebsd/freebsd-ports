--- trap.c.orig	Thu Aug 21 09:45:25 2003
+++ trap.c	Thu Nov  2 13:35:27 2006
@@ -40,9 +40,10 @@
 {
 	static struct sockaddr_in sin;
 
+	if (trap_sock != -1) /* already enabled */
+		close(trap_sock);
+
 	if (enable) {
-		if (trap_sock != -1) /* already enabled */
-			return 0;
 
 		if ((trap_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
 			report(LOG_ERR, "socket: %m");
@@ -51,17 +52,15 @@
 		memset(&sin, 0, sizeof(sin));
 		sin.sin_family = AF_INET;
 		sin.sin_port = htons(SNMPTRAP_PORT);
-		sin.sin_addr.s_addr = INADDR_ANY;
+		sin.sin_addr = cf->trap_ip_addr;
 		if (bind(trap_sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
 			report(LOG_ERR, "bind port %d: %m", ntohs(sin.sin_port));
 			close(trap_sock);
 			trap_sock = -1;
 			return -1;
 		}
-	} else if (trap_sock != -1) {
-		close(trap_sock);
+	} else
 		trap_sock = -1;
-	}
 	return 0;
 }
 
