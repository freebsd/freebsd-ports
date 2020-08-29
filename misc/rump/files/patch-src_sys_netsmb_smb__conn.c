--- src/sys/netsmb/smb_conn.c.orig	2020-08-29 05:05:52 UTC
+++ src/sys/netsmb/smb_conn.c
@@ -112,7 +112,7 @@ smb_listener_cb(kauth_cred_t cred, kauth_action_t acti
 		return KAUTH_RESULT_DEFER;
 
 	result = KAUTH_RESULT_DEFER;
-	req = (enum kauth_network_req)arg0;
+	req = (enum kauth_network_req)(uintptr_t)arg0;
 
 	switch (req) {
 	case KAUTH_REQ_NETWORK_SMB_SHARE_ACCESS: {
