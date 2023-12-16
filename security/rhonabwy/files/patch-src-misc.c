--- src/misc.c.orig	2023-11-14 16:38:17 UTC
+++ src/misc.c
@@ -195,7 +195,7 @@ int _r_get_http_content(const char * url, int x5u_flag
           break;
         }
       }
-      if ((res = curl_easy_perform(curl)) != CURLE_OK) {
+      if ((res = (int) curl_easy_perform(curl)) != CURLE_OK) {
         if (res == CURLE_WRITE_ERROR && datum->size > R_MAX_BODY_SIZE) {
           y_log_message(Y_LOG_LEVEL_ERROR, "_r_get_http_content - Error remote content exceeded size limit of %zu bytes", R_MAX_BODY_SIZE);
           ret = RHN_ERROR_PARAM;
