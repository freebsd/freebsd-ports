--- Curl.xs.orig	Thu Jul 13 14:54:37 2006
+++ Curl.xs	Thu Jul 13 14:55:34 2006
@@ -64,12 +64,17 @@
 
 
 typedef struct {
+#if LIBCURL_VERSION_NUM >= 0x070b01
+    struct curl_httppost * post;
+    struct curl_httppost * last;
+#else
 #if LIBCURL_VERSION_NUM >= 0x070900
     struct HttpPost * post;
     struct HttpPost * last;
 #else
     void * post;
     void * last;
+#endif
 #endif
 } perl_curl_form;
 
