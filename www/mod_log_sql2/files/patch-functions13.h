--- functions13.h.orig	Fri Apr 16 15:03:25 2004
+++ functions13.h	Fri Apr 16 15:03:46 2004
@@ -37,7 +37,7 @@
 
 static const char *extract_request_duration(request_rec *r, char *a)
 {
-	return ap_psprintf(r->pool, "%ld", time(NULL) - r->request_time);
+	return ap_psprintf(r->pool, "%ld", (long)time(NULL) - r->request_time);
 }
 
 static const char *extract_request_timestamp(request_rec *r, char *a)
