--- src/worker-auth.c.orig	2019-01-19 18:47:47 UTC
+++ src/worker-auth.c
@@ -605,7 +605,10 @@ static int recv_cookie_auth_reply(worker_st * ws)
 	case AUTH__REP__OK:
 		if (socketfd != -1) {
 			ws->tun_fd = socketfd;
-
+			if (tun_claim(ws->tun_fd) != 0) {
+				ret = ERR_AUTH_FAIL;
+				goto cleanup;
+			}
 			if (msg->vname == NULL || msg->config == NULL || msg->user_name == NULL || msg->sid.len != sizeof(ws->sid)) {
 				ret = ERR_AUTH_FAIL;
 				goto cleanup;
