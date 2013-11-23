--- pam/gkr-pam-client.c.orig	2008-10-07 12:25:23.000000000 -0400
+++ pam/gkr-pam-client.c	2008-10-07 12:38:36.000000000 -0400
@@ -96,12 +96,12 @@ check_peer_same_uid (int sock)
         struct xucred xuc;
         socklen_t xuc_len = sizeof (xuc);
 
-	if (getsockopt (sock, SOL_SOCKET, LOCAL_PEERCRED, &xuc, &xuc_len) == 0 && 
-	    xuc_len == sizeof (xuc)) {
+	if (getsockopt (sock, 0, LOCAL_PEERCRED, &xuc, &xuc_len) == 0 && 
+	    xuc.cr_version == XUCRED_VERSION) {
 	    	uid = xuc.cr_uid;
 	} else {
 		syslog (GKR_LOG_ERR, "could not get mate-keyring-daemon socket credentials, "
-		        "(returned len %d/%d)\n", xuc_len, (int)sizeof (xuc));
+		        "(returned version %d/%d)\n", xuc.cr_version, XUCRED_VERSION);
 		return -1;   
 	}
 	
