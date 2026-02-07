--- functions.h.orig	2004-09-20 02:50:46 UTC
+++ functions.h
@@ -14,7 +14,11 @@
 
 static const char *extract_remote_address(request_rec *r, char *a)
 {
+#if AP_MODULE_MAGIC_AT_LEAST(20111130,0)
+    return r->useragent_ip;
+#else
     return r->connection->remote_ip;
+#endif
 }
 
 static const char *extract_local_address(request_rec *r, char *a) __attribute__((unused));
