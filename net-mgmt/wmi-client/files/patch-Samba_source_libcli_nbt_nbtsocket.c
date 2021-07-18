--- Samba/source/libcli/nbt/nbtsocket.c.orig	2011-11-22 22:40:25 UTC
+++ Samba/source/libcli/nbt/nbtsocket.c
@@ -45,6 +45,7 @@ static int nbt_name_request_destructor(struct nbt_name
 		req->name_trn_id = 0;
 	}
 	if (req->te) {
+		talloc_free(req->te);
 		req->te = NULL;
 	}
 	if (req->nbtsock->send_queue == NULL) {
@@ -168,8 +169,23 @@ static void nbt_name_socket_recv(struct nbt_name_socke
 		return;
 	}
 
+	/*
+	 * Given a zero length, data_blob_talloc() returns the
+	 * NULL blob {NULL, 0}.
+	 *
+	 * We only want to error return here on a real out of memory condition
+	 * (i.e. dsize != 0, so the UDP packet has data, but the return of the
+	 * allocation failed, so blob.data==NULL).
+	 *
+	 * Given an actual zero length UDP packet having blob.data == NULL
+	 * isn't an out of memory error condition, that's the defined semantics
+	 * of data_blob_talloc() when asked for zero bytes.
+	 *
+	 * We still need to continue to do the zero-length socket_recvfrom()
+	 * read in order to clear the "read pending" condition on the socket.
+	 */
 	blob = data_blob_talloc(tmp_ctx, NULL, dsize);
-	if (blob.data == NULL) {
+	if (blob.data == NULL && dsize != 0) {
 		talloc_free(tmp_ctx);
 		return;
 	}
@@ -226,6 +242,16 @@ static void nbt_name_socket_recv(struct nbt_name_socke
 		return;
 	}
 
+	talloc_steal(req, packet);
+	talloc_steal(req, src);
+	talloc_free(tmp_ctx);
+	nbt_name_socket_handle_response_packet(req, packet, src);
+}
+
+void nbt_name_socket_handle_response_packet(struct nbt_name_request *req,
+					    struct nbt_name_packet *packet,
+					    struct socket_address *src)
+{
 	/* if this is a WACK response, this we need to go back to waiting,
 	   but perhaps increase the timeout */
 	if ((packet->operation & NBT_OPCODE) == NBT_OPCODE_WACK) {
@@ -246,7 +272,6 @@ static void nbt_name_socket_recv(struct nbt_name_socke
 		req->te = event_add_timed(req->nbtsock->event_ctx, req, 
 					  timeval_current_ofs(req->timeout, 0),
 					  nbt_name_socket_timeout, req);
-		talloc_free(tmp_ctx);
 		return;
 	}
 	
@@ -268,7 +293,6 @@ static void nbt_name_socket_recv(struct nbt_name_socke
 	/* if we don't want multiple replies then we are done */
 	if (req->allow_multiple_replies &&
 	    req->num_replies < NBT_MAX_REPLIES) {
-		talloc_free(tmp_ctx);
 		return;
 	}
 
@@ -278,13 +302,11 @@ static void nbt_name_socket_recv(struct nbt_name_socke
 
 done:
     if (DEBUGLVL(9)) {
-        talloc_report(tmp_ctx, stdout);
         talloc_report(req, stdout);
     }
 	if (req->async.fn) {
 		req->async.fn(req);
 	}
-	talloc_free(tmp_ctx);
 }
 
 /*
