--- txt_format.c.orig	2018-11-09 09:42:02 UTC
+++ txt_format.c
@@ -417,7 +417,7 @@ int fmt_seconds(ci_request_t *req, char *buf,int len, 
 {
     time_t tm;
     time(&tm);
-    return snprintf(buf, len, "%ld", tm);
+    return snprintf(buf, len, "%" PRId64 , (uint64_t) tm);
 }
 
 int fmt_httpclientip(ci_request_t *req, char *buf,int len, const char *param)
