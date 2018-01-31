--- src/lib-auth/auth-client-request.c.orig	2017-10-05 17:10:44 UTC
+++ src/lib-auth/auth-client-request.c
@@ -180,6 +180,7 @@ void auth_client_request_abort(struct auth_client_requ
 
 	auth_client_send_cancel(request->conn->client, request->id);
 	call_callback(request, AUTH_REQUEST_STATUS_ABORT, NULL, NULL);
+	pool_unref(&request->pool);
 }
 
 unsigned int auth_client_request_get_id(struct auth_client_request *request)
