--- clientloop.c.orig	Fri Aug 13 13:18:01 2004
+++ clientloop.c	Mon Sep 20 05:04:48 2004
@@ -1581,7 +1581,7 @@
 
 	if (strcmp(ctype, "forwarded-tcpip") == 0) {
 		c = client_request_forwarded_tcpip(ctype, rchan);
-	} else if (strcmp(ctype, "x11") == 0) {
+	} else if (strcmp(ctype, "x11") == 0 && options.forward_x11) {
 		c = client_request_x11(ctype, rchan);
 	} else if (strcmp(ctype, "auth-agent@openssh.com") == 0) {
 		c = client_request_agent(ctype, rchan);
