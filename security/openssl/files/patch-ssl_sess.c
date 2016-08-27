CVE-2016-2177

--- ssl/ssl_sess.c.orig
+++ ssl/ssl_sess.c
@@ -573,7 +573,7 @@ int ssl_get_prev_session(SSL *s, unsigned char *session_id, int len,
     int r;
 #endif
 
-    if (session_id + len > limit) {
+    if (limit - session_id < len) {
         fatal = 1;
         goto err;
     }
