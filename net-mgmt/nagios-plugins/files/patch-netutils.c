--- plugins/netutils.c.orig	Sun Aug 10 08:31:02 2003
+++ plugins/netutils.c	Sat Nov 27 13:10:43 2004
@@ -97,7 +97,7 @@
 	fd_set readfds;
 	int recv_length = 0;
 
-	result = my_connect (server_address, server_port, &sd, IPPROTO_TCP);
+	result = nagios_my_connect (server_address, server_port, &sd, IPPROTO_TCP);
 	if (result != STATE_OK)
 		return STATE_CRITICAL;
 
@@ -175,7 +175,7 @@
 
 	result = STATE_OK;
 
-	result = my_connect (server_address, server_port, &sd, proto);
+	result = nagios_my_connect (server_address, server_port, &sd, proto);
 	if (result != STATE_OK)
 		return STATE_CRITICAL;
 
@@ -227,7 +227,7 @@
 {
 	int result;
 
-	result = my_connect (host_name, port, sd, IPPROTO_TCP);
+	result = nagios_my_connect (host_name, port, sd, IPPROTO_TCP);
 
 	return result;
 }
@@ -239,7 +239,7 @@
 {
 	int result;
 
-	result = my_connect (host_name, port, sd, IPPROTO_UDP);
+	result = nagios_my_connect (host_name, port, sd, IPPROTO_UDP);
 
 	return result;
 }
@@ -247,7 +247,7 @@
 
 /* opens a tcp or udp connection to a remote host */
 int
-my_connect (const char *host_name, int port, int *sd, int proto)
+nagios_my_connect (const char *host_name, int port, int *sd, int proto)
 {
 	struct addrinfo hints;
 	struct addrinfo *res;
