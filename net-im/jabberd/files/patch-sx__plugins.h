diff --git a/sx/plugins.h b/sx/plugins.h
index b5d3934..65dae93 100644
--- a/sx/plugins.h
+++ sx/plugins.h
@@ -159,7 +159,7 @@ typedef struct _sx_compress_conn_st {
 JABBERD2_API int sx_ack_init(sx_env_t env, sx_plugin_t p, va_list args);
 
 /* websocket wrapper plugin */
-//#ifdef USE_WEBSOCKET
+#ifdef USE_WEBSOCKET
 #include <http_parser.h>
 #include <util/util.h>
 
@@ -183,7 +183,7 @@ typedef struct _sx_websocket_conn_st {
     xht                     headers;
     void                    *frame;
 } *_sx_websocket_conn_t;
-//#endif
+#endif
 
 #ifdef __cplusplus
 }
