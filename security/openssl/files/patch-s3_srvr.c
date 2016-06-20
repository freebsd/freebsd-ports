CVE-2016-2177

--- ssl/s3_srvr.c.orig
+++ ssl/s3_srvr.c
@@ -980,7 +980,7 @@ int ssl3_get_client_hello(SSL *s)
 
         session_length = *(p + SSL3_RANDOM_SIZE);
 
-        if (p + SSL3_RANDOM_SIZE + session_length + 1 >= d + n) {
+        if (SSL3_RANDOM_SIZE + session_length + 1 >= (d + n) - p) {
             al = SSL_AD_DECODE_ERROR;
             SSLerr(SSL_F_SSL3_GET_CLIENT_HELLO, SSL_R_LENGTH_TOO_SHORT);
             goto f_err;
@@ -998,7 +998,7 @@ int ssl3_get_client_hello(SSL *s)
     /* get the session-id */
     j = *(p++);
 
-    if (p + j > d + n) {
+    if ((d + n) - p < j) {
         al = SSL_AD_DECODE_ERROR;
         SSLerr(SSL_F_SSL3_GET_CLIENT_HELLO, SSL_R_LENGTH_TOO_SHORT);
         goto f_err;
@@ -1054,14 +1054,14 @@ int ssl3_get_client_hello(SSL *s)
 
     if (SSL_IS_DTLS(s)) {
         /* cookie stuff */
-        if (p + 1 > d + n) {
+        if ((d + n) - p < 1) {
             al = SSL_AD_DECODE_ERROR;
             SSLerr(SSL_F_SSL3_GET_CLIENT_HELLO, SSL_R_LENGTH_TOO_SHORT);
             goto f_err;
         }
         cookie_len = *(p++);
 
-        if (p + cookie_len > d + n) {
+        if ((d + n ) - p < cookie_len) {
             al = SSL_AD_DECODE_ERROR;
             SSLerr(SSL_F_SSL3_GET_CLIENT_HELLO, SSL_R_LENGTH_TOO_SHORT);
             goto f_err;
@@ -1131,7 +1131,7 @@ int ssl3_get_client_hello(SSL *s)
         }
     }
 
-    if (p + 2 > d + n) {
+    if ((d + n ) - p < 2) {
         al = SSL_AD_DECODE_ERROR;
         SSLerr(SSL_F_SSL3_GET_CLIENT_HELLO, SSL_R_LENGTH_TOO_SHORT);
         goto f_err;
@@ -1145,7 +1145,7 @@ int ssl3_get_client_hello(SSL *s)
     }
 
     /* i bytes of cipher data + 1 byte for compression length later */
-    if ((p + i + 1) > (d + n)) {
+    if ((d + n) - p < i + 1) {
         /* not enough data */
         al = SSL_AD_DECODE_ERROR;
         SSLerr(SSL_F_SSL3_GET_CLIENT_HELLO, SSL_R_LENGTH_MISMATCH);
@@ -1211,7 +1211,7 @@ int ssl3_get_client_hello(SSL *s)
 
     /* compression */
     i = *(p++);
-    if ((p + i) > (d + n)) {
+    if ((d + n) - p < i) {
         /* not enough data */
         al = SSL_AD_DECODE_ERROR;
         SSLerr(SSL_F_SSL3_GET_CLIENT_HELLO, SSL_R_LENGTH_MISMATCH);
