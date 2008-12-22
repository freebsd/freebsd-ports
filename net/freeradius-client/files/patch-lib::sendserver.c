--- lib/sendserver.c
+++ lib/sendserver.c
@@ -196,6 +196,7 @@
 	char            send_buffer[BUFFER_LEN];
 	int		retries;
 	VALUE_PAIR 	*vp;
+	unsigned long	nasaddr;
 
 	server_name = data->server;
 	if (server_name == NULL || server_name[0] == '\0')
@@ -259,6 +262,9 @@
 	/*
 	 * Fill in NAS-IP-Address
 	 */
+	nas_ipaddr = rc_nasaddress(rh);
+	if (nas_ipaddr != 0)
+		sinlocal.sin_addr.s_addr = htonl(nas_ipaddr);
 	if (sinlocal.sin_addr.s_addr == htonl(INADDR_ANY)) {
 		if (rc_get_srcaddr(SA(&sinlocal), SA(&sinremote)) != 0) {
 			close (sockfd);
