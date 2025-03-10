--- Curl_Multi.xsh.orig	2021-05-12 05:52:08 UTC
+++ Curl_Multi.xsh
@@ -66,9 +66,21 @@ cb_multi_socket( CURL *easy_handle, curl_socket_t s, i
 	perl_curl_multi_t *multi;
 	perl_curl_easy_t *easy;
 
+	/* Check if userptr is NULL */
+	if (!userptr) {
+		return -1;
+	}
 	multi = (perl_curl_multi_t *) userptr;
 
-	(void) curl_easy_getinfo( easy_handle, CURLINFO_PRIVATE, (void *) &easy );
+	CURLcode res = curl_easy_getinfo( easy_handle, CURLINFO_PRIVATE, (void *) &easy );
+	if (res != CURLE_OK || !easy) {
+		return -1;
+	}
+
+	/* Check if the callback is set */
+	if (multi->cb[CB_MULTI_SOCKET].func == NULL) {
+		return -1;
+	}
 
 	/* $multi, $easy, $socket, $what, $socketdata, $userdata */
 	SV *args[] = {
