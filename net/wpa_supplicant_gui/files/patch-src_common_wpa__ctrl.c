--- src/common/wpa_ctrl.c.orig	2015-09-27 19:02:05 UTC
+++ src/common/wpa_ctrl.c
@@ -477,6 +477,10 @@ int wpa_ctrl_request(struct wpa_ctrl *ct
 	char *cmd_buf = NULL;
 	size_t _cmd_len;
 
+#ifndef QT_NO_DEBUG
+	fprintf(stderr, "CMD-SEND: %*s\n", cmd_len, cmd);
+#endif // QT_NO_DEBUG
+
 #ifdef CONFIG_CTRL_IFACE_UDP
 	if (ctrl->cookie) {
 		char *pos;
@@ -554,6 +558,9 @@ retry_send:
 				continue;
 			}
 			*reply_len = res;
+#ifndef QT_NO_DEBUG
+			fprintf(stderr, "CMD-RECV: %*s\n", *reply_len, reply);
+#endif // QT_NO_DEBUG
 			break;
 		} else {
 			return -2;
