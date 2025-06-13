--- src/request.c.orig	2025-06-04 08:40:48 UTC
+++ src/request.c
@@ -1189,16 +1189,16 @@ static S3Status setup_curl(Request *request,
 
     // Ask curl to parse the Last-Modified header.  This is easier than
     // parsing it ourselves.
-    curl_easy_setopt_safe(CURLOPT_FILETIME, 1);
+    curl_easy_setopt_safe(CURLOPT_FILETIME, 1l);
 
     // Curl docs suggest that this is necessary for multithreaded code.
     // However, it also points out that DNS timeouts will not be honored
     // during DNS lookup, which can be worked around by using the c-ares
     // library, which we do not do yet.
-    curl_easy_setopt_safe(CURLOPT_NOSIGNAL, 1);
+    curl_easy_setopt_safe(CURLOPT_NOSIGNAL, 1l);
 
     // Turn off Curl's built-in progress meter
-    curl_easy_setopt_safe(CURLOPT_NOPROGRESS, 1);
+    curl_easy_setopt_safe(CURLOPT_NOPROGRESS, 1l);
 
     // xxx todo - support setting the proxy for Curl to use (can't use https
     // for proxies though)
@@ -1207,20 +1207,20 @@ static S3Status setup_curl(Request *request,
 
     // I think this is useful - we don't need interactive performance, we need
     // to complete large operations quickly
-    curl_easy_setopt_safe(CURLOPT_TCP_NODELAY, 1);
+    curl_easy_setopt_safe(CURLOPT_TCP_NODELAY, 1l);
 
     // Don't use Curl's 'netrc' feature
     curl_easy_setopt_safe(CURLOPT_NETRC, CURL_NETRC_IGNORED);
 
     // Don't verify S3's certificate unless S3_INIT_VERIFY_PEER is set.
     // The request_context may be set to override this
-    curl_easy_setopt_safe(CURLOPT_SSL_VERIFYPEER, verifyPeer);
+    curl_easy_setopt_safe(CURLOPT_SSL_VERIFYPEER, (long)verifyPeer);
 
     // Follow any redirection directives that S3 sends
-    curl_easy_setopt_safe(CURLOPT_FOLLOWLOCATION, 1);
+    curl_easy_setopt_safe(CURLOPT_FOLLOWLOCATION, 1l);
 
     // A safety valve in case S3 goes bananas with redirects
-    curl_easy_setopt_safe(CURLOPT_MAXREDIRS, 10);
+    curl_easy_setopt_safe(CURLOPT_MAXREDIRS, 10l);
 
     // Set the User-Agent; maybe Amazon will track these?
     curl_easy_setopt_safe(CURLOPT_USERAGENT, userAgentG);
@@ -1229,12 +1229,12 @@ static S3Status setup_curl(Request *request,
     // less than 1K per second for more than 15 seconds.
     // xxx todo - make these configurable
     // xxx todo - allow configurable max send and receive speed
-    curl_easy_setopt_safe(CURLOPT_LOW_SPEED_LIMIT, 1024);
-    curl_easy_setopt_safe(CURLOPT_LOW_SPEED_TIME, 15);
+    curl_easy_setopt_safe(CURLOPT_LOW_SPEED_LIMIT, 1024l);
+    curl_easy_setopt_safe(CURLOPT_LOW_SPEED_TIME, 15l);
 
 
     if (params->timeoutMs > 0) {
-        curl_easy_setopt_safe(CURLOPT_TIMEOUT_MS, params->timeoutMs);
+        curl_easy_setopt_safe(CURLOPT_TIMEOUT_MS, (long)params->timeoutMs);
     }
 
 
@@ -1293,16 +1293,16 @@ static S3Status setup_curl(Request *request,
     // Set request type.
     switch (params->httpRequestType) {
     case HttpRequestTypeHEAD:
-        curl_easy_setopt_safe(CURLOPT_NOBODY, 1);
+        curl_easy_setopt_safe(CURLOPT_NOBODY, 1l);
         break;
     case HttpRequestTypePOST:
         curl_easy_setopt_safe(CURLOPT_CUSTOMREQUEST, "POST");
-        curl_easy_setopt_safe(CURLOPT_UPLOAD, 1);
+        curl_easy_setopt_safe(CURLOPT_UPLOAD, 1l);
         break;
 
     case HttpRequestTypePUT:
     case HttpRequestTypeCOPY:
-        curl_easy_setopt_safe(CURLOPT_UPLOAD, 1);
+        curl_easy_setopt_safe(CURLOPT_UPLOAD, 1l);
         break;
     case HttpRequestTypeDELETE:
         curl_easy_setopt_safe(CURLOPT_CUSTOMREQUEST, "DELETE");
