diff --git a/monitor_wrap.c b/monitor_wrap.c
index b379f05..d39d491 100644
--- monitor_wrap.c
+++ monitor_wrap.c
@@ -153,10 +153,8 @@ mm_request_receive(int sock, Buffer *m)
 	debug3("%s entering", __func__);
 
 	if (atomicio(read, sock, buf, sizeof(buf)) != sizeof(buf)) {
-		if (errno == EPIPE) {
-			error("%s: socket closed", __func__);
+		if (errno == EPIPE)
 			cleanup_exit(255);
-		}
 		fatal("%s: read: %s", __func__, strerror(errno));
 	}
 	msg_len = get_u32(buf);
