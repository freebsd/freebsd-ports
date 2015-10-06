diff --git a/plugins/gssapi.c b/plugins/gssapi.c
index 2fd1b3b..0992912 100644
--- a/plugins/gssapi.c
+++ b/plugins/gssapi.c
@@ -1490,8 +1490,10 @@ static int gssapi_client_mech_step(void *conn_context,
     *clientout = NULL;
     *clientoutlen = 0;
     
+#if 0
     params->utils->log(NULL, SASL_LOG_DEBUG,
 		       "GSSAPI client step %d", text->state);
+#endif
 
     switch (text->state) {
 
