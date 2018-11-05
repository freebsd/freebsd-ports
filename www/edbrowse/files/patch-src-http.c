--- src/http.c.orig	2018-06-27 17:42:33 UTC
+++ src/http.c
@@ -1555,7 +1555,9 @@ void ebcurl_setError(CURLcode curlret, c
 		break;
 
 	case CURLE_PEER_FAILED_VERIFICATION:
+#if LIBCURL_VERSION_NUM < 0x073e00
 	case CURLE_SSL_CACERT:
+#endif
 		(*fn) (MSG_NoCertify, host);
 		break;
 
