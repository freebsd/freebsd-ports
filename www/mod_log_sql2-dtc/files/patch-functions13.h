--- ./functions13.h.orig	2004-04-29 18:05:24.000000000 +0000
+++ ./functions13.h	2009-12-27 01:38:18.620401873 +0000
@@ -37,7 +37,7 @@
 
 static const char *extract_request_duration(request_rec *r, char *a)
 {
-	return ap_psprintf(r->pool, "%ld", time(NULL) - r->request_time);
+	return ap_psprintf(r->pool, "%ld", (long)time(NULL) - r->request_time);
 }
 
 static const char *extract_request_timestamp(request_rec *r, char *a)
