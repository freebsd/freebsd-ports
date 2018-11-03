--- daemon/http-tx-mgr.c.orig	2018-02-02 05:55:07 UTC
+++ daemon/http-tx-mgr.c
@@ -68,6 +68,22 @@
 #define USER_AGENT_OS "BSD"
 #endif
 
+#ifdef __FreeBSD__
+#define USER_AGENT_OS "FreeBSD"
+#endif
+
+#ifdef __DragonFly__
+#define USER_AGENT_OS "DragonFly"
+#endif
+
+#ifdef __NetBSD__
+#define USER_AGENT_OS "NetBSD"
+#endif
+
+#ifdef __OpenBSD__
+#define USER_AGENT_OS "OpenBSD"
+#endif
+
 struct _Connection {
     CURL *curl;
     gint64 ctime;               /* Used to clean up unused connection. */
@@ -1091,7 +1107,9 @@ curl_error_to_http_task_error (int curl_
     case CURLE_SSL_CONNECT_ERROR:
     case CURLE_PEER_FAILED_VERIFICATION:
     case CURLE_SSL_CERTPROBLEM:
+#if LIBCURL_VERSION_NUM < 0x073e00
     case CURLE_SSL_CACERT:
+#endif
     case CURLE_SSL_CACERT_BADFILE:
     case CURLE_SSL_ISSUER_ERROR:
         return HTTP_TASK_ERR_SSL;
