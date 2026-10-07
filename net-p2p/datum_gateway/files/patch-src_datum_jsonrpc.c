--- src/datum_jsonrpc.c.orig	2025-07-16 19:51:32 UTC
+++ src/datum_jsonrpc.c
@@ -146,7 +146,6 @@
 	struct upload_buffer upload_data;
 	json_error_t err = { };
 	struct curl_slist *headers = NULL;
-	char len_hdr[64];
 	char curl_err_str[CURL_ERROR_SIZE];
 	bool check_for_result = true;
 	
@@ -172,10 +171,9 @@
 	
 	upload_data.buf = rpc_req;
 	upload_data.len = strlen(rpc_req);
-	sprintf(len_hdr, "Content-Length: %lu",(unsigned long) upload_data.len);
+	curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)upload_data.len);
 	
 	headers = curl_slist_append(headers, "Content-type: application/json");
-	headers = curl_slist_append(headers, len_hdr);
 	headers = curl_slist_append(headers, "Expect:");
 	
 	if (extra_header) {
