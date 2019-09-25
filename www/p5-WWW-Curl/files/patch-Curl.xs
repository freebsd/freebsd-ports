--- Curl.xs.orig	2019-09-17 09:12:44 UTC
+++ Curl.xs
@@ -73,7 +73,7 @@ typedef struct {
 #ifdef __CURL_MULTI_H
     struct CURLM *curlm;
 #else
-    struct void *curlm;
+    void *curlm;
 #endif
 } perl_curl_multi;
 
