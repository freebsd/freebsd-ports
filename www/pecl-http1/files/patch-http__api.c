--- http_api.c.orig	2016-07-19 07:12:32 UTC
+++ http_api.c
@@ -349,6 +349,7 @@ PHP_HTTP_API STATUS _http_get_request_bo
 	*length = 0;
 	*body = NULL;
 	
+#if (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 6)
 	if (SG(request_info).raw_post_data) {
 		*length = SG(request_info).raw_post_data_length;
 		*body = SG(request_info).raw_post_data;
@@ -357,7 +358,9 @@ PHP_HTTP_API STATUS _http_get_request_bo
 			*body = estrndup(*body, *length);
 		}
 		return SUCCESS;
-	} else if (sapi_module.read_post && !HTTP_G->read_post_data) {
+	}
+#endif
+	if (sapi_module.read_post && !HTTP_G->read_post_data) {
 		char *buf = emalloc(4096);
 		int len;
 		
@@ -382,8 +385,10 @@ PHP_HTTP_API STATUS _http_get_request_bo
 			return FAILURE;
 		}
 		
+#if (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 6)
 		SG(request_info).raw_post_data = *body;
 		SG(request_info).raw_post_data_length = *length;
+#endif
 		
 		if (dup) {
 			*body = estrndup(*body, *length);
@@ -400,9 +405,13 @@ PHP_HTTP_API php_stream *_http_get_reque
 {
 	php_stream *s = NULL;
 	
+#if (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 6)
 	if (SG(request_info).raw_post_data) {
 		s = php_stream_open_wrapper("php://input", "rb", 0, NULL);
 	} else if (sapi_module.read_post && !HTTP_G->read_post_data) {
+#else
+	if (sapi_module.read_post && !HTTP_G->read_post_data) {
+#endif
 		HTTP_G->read_post_data = 1;
 		
 		if ((s = php_stream_temp_new())) {
