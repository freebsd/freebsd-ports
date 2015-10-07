--- plugins/gssapi.c.orig
+++ plugins/gssapi.c
@@ -1490,8 +1490,10 @@
     *clientout = NULL;
     *clientoutlen = 0;
     
+#if 0
     params->utils->log(NULL, SASL_LOG_DEBUG,
 		       "GSSAPI client step %d", text->state);
+#endif
 
     switch (text->state) {
 
