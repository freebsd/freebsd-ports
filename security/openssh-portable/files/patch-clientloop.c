--- clientloop.c.orig	Fri Apr 20 09:17:51 2001
+++ clientloop.c	Sat May 26 15:18:51 2001
@@ -1131,7 +1131,7 @@
 
 	if (strcmp(ctype, "forwarded-tcpip") == 0) {
 		c = client_request_forwarded_tcpip(ctype, rchan);
-	} else if (strcmp(ctype, "x11") == 0) {
+	} else if (strcmp(ctype, "x11") == 0 && options.forward_x11) {
 		c = client_request_x11(ctype, rchan);
 	} else if (strcmp(ctype, "auth-agent@openssh.com") == 0) {
 		c = client_request_agent(ctype, rchan);
