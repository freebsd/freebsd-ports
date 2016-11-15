--- src/lib-http/http-client-request.c.orig	2016-10-27 12:26:28 UTC
+++ src/lib-http/http-client-request.c
@@ -786,10 +786,16 @@ int http_client_request_send_payload(str
 	i_assert(data != NULL);
 
 	ret = http_client_request_continue_payload(&req, data, size);
-	if (ret < 0)
+	if (ret < 0) {
+		/* failed to send payload */
 		*_req = NULL;
-	else {
-		i_assert(ret == 0);
+	} else if (ret > 0) {
+		/* premature end of request;
+		   server sent error before all payload could be sent */
+		ret = -1;
+		*_req = NULL;
+	} else {
+		/* not finished sending payload */
 		i_assert(req != NULL);
 	}
 	return ret;
