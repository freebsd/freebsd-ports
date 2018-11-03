--- src/low-level/feed/newsfeed.c.orig	2018-09-12 11:54:16 UTC
+++ src/low-level/feed/newsfeed.c
@@ -535,7 +535,9 @@ static int curl_error_convert(int curl_r
   case CURLE_SSL_ENGINE_SETFAILED:
   case CURLE_SSL_CERTPROBLEM:
   case CURLE_SSL_CIPHER:
+#if LIBCURL_VERSION_NUM < 0x073e00
   case CURLE_SSL_CACERT:
+#endif
   case CURLE_FTP_SSL_FAILED:
   case CURLE_SSL_ENGINE_INITFAILED:
     return NEWSFEED_ERROR_SSL;
