--- src/sys/kern/uipc_socket.c.orig	2020-08-29 05:02:44 UTC
+++ src/sys/kern/uipc_socket.c
@@ -411,7 +411,7 @@ socket_listener_cb(kauth_cred_t cred, kauth_action_t a
 	enum kauth_network_req req;
 
 	result = KAUTH_RESULT_DEFER;
-	req = (enum kauth_network_req)arg0;
+	req = (enum kauth_network_req)(uintptr_t)arg0;
 
 	if ((action != KAUTH_NETWORK_SOCKET) &&
 	    (action != KAUTH_NETWORK_BIND))
