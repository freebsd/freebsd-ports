--- mod_blowchunks-1.3.c.orig	Sat Jun 22 22:44:01 2002
+++ mod_blowchunks-1.3.c	Sat Jun 22 22:45:18 2002
@@ -56,8 +56,10 @@
     ap_table_do(blowchunks_check_one_header,&found,r->headers_in,
 	    "Transfer-Encoding",NULL);
     if (found==TRUE) {
+#ifdef LOG_BLOWCHUNK
         ap_log_rerror(APLOG_MARK, APLOG_NOERRNO|APLOG_ERR, r,
 	    "Transfer-Encoding: chunked - denied and logged");
+#endif
 	return HTTP_BAD_REQUEST;
     }
     return DECLINED;
