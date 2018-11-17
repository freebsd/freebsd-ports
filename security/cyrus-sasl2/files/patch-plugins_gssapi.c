--- plugins/gssapi.c.orig	2016-01-30 14:06:08 UTC
+++ plugins/gssapi.c
@@ -1531,8 +1531,10 @@ static int gssapi_client_mech_step(void 
     *clientout = NULL;
     *clientoutlen = 0;
     
+#if 0
     params->utils->log(params->utils->conn, SASL_LOG_DEBUG,
 		       "GSSAPI client step %d", text->state);
+#endif
 
     switch (text->state) {
 
