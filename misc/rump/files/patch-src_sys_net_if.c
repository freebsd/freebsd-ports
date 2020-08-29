--- src/sys/net/if.c.orig	2020-08-29 05:07:31 UTC
+++ src/sys/net/if.c
@@ -233,7 +233,7 @@ if_listener_cb(kauth_cred_t cred, kauth_action_t actio
 	enum kauth_network_req req;
 
 	result = KAUTH_RESULT_DEFER;
-	req = (enum kauth_network_req)arg1;
+	req = (enum kauth_network_req)(uintptr_t)arg1;
 
 	if (action != KAUTH_NETWORK_INTERFACE)
 		return result;
