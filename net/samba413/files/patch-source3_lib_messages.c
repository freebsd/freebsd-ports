--- source3/lib/messages.c.orig	2020-07-09 09:33:56 UTC
+++ source3/lib/messages.c
@@ -157,7 +157,7 @@ struct messaging_rec *messaging_rec_create(
 
 	{
 		struct messaging_rec rec;
-		int64_t fds64[num_fds];
+		int64_t fds64[MAX(1, num_fds)];
 		size_t i;
 
 		for (i=0; i<num_fds; i++) {
@@ -391,7 +391,7 @@ static void messaging_recv_cb(struct tevent_context *e
 		private_data, struct messaging_context);
 	struct server_id_buf idbuf;
 	struct messaging_rec rec;
-	int64_t fds64[MIN(num_fds, INT8_MAX)];
+	int64_t fds64[MAX(1, MIN(num_fds, INT8_MAX))];
 	size_t i;
 
 	if (msg_len < MESSAGE_HDR_LENGTH) {
@@ -1371,7 +1371,7 @@ static void messaging_dispatch_rec(struct messaging_co
 
 	if (ev != msg_ctx->event_ctx) {
 		struct iovec iov;
-		int fds[rec->num_fds];
+		int fds[MAX(1, rec->num_fds)];
 		int ret;
 
 		/*
