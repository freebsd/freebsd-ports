--- plugins/netutils.c.orig	2015-07-30 21:40:06 UTC
+++ plugins/netutils.c
@@ -158,7 +158,7 @@ int
 np_net_connect (const char *host_name, int port, int *sd, int proto)
 {
 	struct addrinfo hints;
-	struct addrinfo *res;
+	struct addrinfo *res, *res0;
 	struct sockaddr_un su;
 	char port_str[6], host[MAX_HOST_ADDRESS_LENGTH];
 	size_t len;
@@ -185,12 +185,13 @@ np_net_connect (const char *host_name, i
 		memcpy (host, host_name, len);
 		host[len] = '\0';
 		snprintf (port_str, sizeof (port_str), "%d", port);
-		result = getaddrinfo (host, port_str, &hints, &res);
+		result = getaddrinfo (host, port_str, &hints, &res0);
 
 		if (result != 0) {
 			printf ("%s\n", gai_strerror (result));
 			return STATE_UNKNOWN;
 		}
+		res = res0;
 
 		while (res) {
 			/* attempt to create a socket */
@@ -198,7 +199,7 @@ np_net_connect (const char *host_name, i
 
 			if (*sd < 0) {
 				printf ("%s\n", _("Socket creation failed"));
-				freeaddrinfo (res);
+				freeaddrinfo (res0);
 				return STATE_UNKNOWN;
 			}
 
@@ -221,7 +222,7 @@ np_net_connect (const char *host_name, i
 			close (*sd);
 			res = res->ai_next;
 		}
-		freeaddrinfo (res);
+		freeaddrinfo (res0);
 	}
 	/* else the hostname is interpreted as a path to a unix socket */
 	else {
