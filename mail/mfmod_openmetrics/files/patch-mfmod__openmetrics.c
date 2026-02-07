--- mfmod_openmetrics.c.orig	2023-02-10 08:24:56 UTC
+++ mfmod_openmetrics.c
@@ -992,7 +992,7 @@ openmetrics_set(long count, MFMOD_PARAM *p, MFMOD_PARA
 /*
  * Server
  */
-static int
+static enum MHD_Result
 reassemble_get_args(void *cls, enum MHD_ValueKind kind,
 		    const char *key, const char *value)
 {
@@ -1373,7 +1373,7 @@ http_response(struct MHD_Connection *conn,
 	return ret;
 }
 
-static int
+static enum MHD_Result
 openmetrics_httpd_handler(void *cls,
 		      struct MHD_Connection *conn,
 		      const char *url, const char *method,
