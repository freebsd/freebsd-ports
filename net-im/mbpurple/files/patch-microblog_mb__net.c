--- microblog/mb_net.c.orig	2016-06-20 15:55:29 UTC
+++ microblog/mb_net.c
@@ -160,13 +160,13 @@ void mb_conn_fetch_url_cb(PurpleUtilFetc
 	conn_data->fetch_url_data = NULL;
 
 	if(error_message != NULL) {
-		mb_conn_data_free(conn_data);
 		if(conn_data->handler) {
 			retval = conn_data->handler(conn_data, conn_data->handler_data, error_message);
 		}
 		if(ma->gc != NULL) {
 			purple_connection_error_reason(ma->gc, PURPLE_CONNECTION_ERROR_NETWORK_ERROR, error_message);
 		}
+        mb_conn_data_free(conn_data);
 	} else {
 		mb_http_data_post_read(conn_data->response, url_text, len);
 		if(conn_data->handler) {
