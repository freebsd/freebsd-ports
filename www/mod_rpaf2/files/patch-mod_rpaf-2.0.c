PR: ports/179525 	Fix for mod_rpaf2 compatibility with Apache 2.4
========================================================================
--- ./mod_rpaf-2.0.c.orig
+++ ./mod_rpaf-2.0.c
@@ -86,6 +86,23 @@
     request_rec *r;
 } rpaf_cleanup_rec;
 
+
+inline apr_sockaddr_t * rpaf_client_addr(conn_rec *c) {
+#if AP_SERVER_MAJORVERSION_NUMBER >= 2 && AP_SERVER_MINORVERSION_NUMBER >= 4
+  return c->client_addr;
+#else
+  return c->remote_addr;
+#endif
+}
+
+inline char * rpaf_client_ip(conn_rec *c) {
+#if AP_SERVER_MAJORVERSION_NUMBER >= 2 && AP_SERVER_MINORVERSION_NUMBER >= 4
+  return c->client_ip;
+#else
+  return c->remote_ip;
+#endif
+}
+
 static void *rpaf_create_server_cfg(apr_pool_t *p, server_rec *s) {
     rpaf_server_cfg *cfg = (rpaf_server_cfg *)apr_pcalloc(p, sizeof(rpaf_server_cfg));
     if (!cfg)
@@ -147,8 +164,9 @@
 
 static apr_status_t rpaf_cleanup(void *data) {
     rpaf_cleanup_rec *rcr = (rpaf_cleanup_rec *)data;
-    rcr->r->connection->remote_ip   = apr_pstrdup(rcr->r->connection->pool, rcr->old_ip);
-    rcr->r->connection->remote_addr->sa.sin.sin_addr.s_addr = apr_inet_addr(rcr->r->connection->remote_ip);
+    char *remote_ip = rpaf_client_ip(rcr->r->connection);
+    strcpy(remote_ip,apr_pstrdup(rcr->r->connection->pool, rcr->old_ip)); 
+    rpaf_client_addr(rcr->r->connection)->sa.sin.sin_addr.s_addr = apr_inet_addr(remote_ip);
     return APR_SUCCESS;
 }
 
@@ -160,8 +178,8 @@
 
     if (!cfg->enable)
         return DECLINED;
-
-    if (is_in_array(r->connection->remote_ip, cfg->proxy_ips) == 1) {
+    char *remote_ip = rpaf_client_ip(r->connection);
+    if (is_in_array(remote_ip, cfg->proxy_ips) == 1) {
         /* check if cfg->headername is set and if it is use
            that instead of X-Forwarded-For by default */
         if (cfg->headername && (fwdvalue = apr_table_get(r->headers_in, cfg->headername))) {
@@ -180,11 +198,11 @@
                 if (*fwdvalue != '\0')
                     ++fwdvalue;
             }
-            rcr->old_ip = apr_pstrdup(r->connection->pool, r->connection->remote_ip);
+            rcr->old_ip = apr_pstrdup(r->connection->pool, remote_ip);
             rcr->r = r;
             apr_pool_cleanup_register(r->pool, (void *)rcr, rpaf_cleanup, apr_pool_cleanup_null);
-            r->connection->remote_ip = apr_pstrdup(r->connection->pool, ((char **)arr->elts)[((arr->nelts)-1)]);
-            r->connection->remote_addr->sa.sin.sin_addr.s_addr = apr_inet_addr(r->connection->remote_ip);
+            strcpy(remote_ip,apr_pstrdup(r->connection->pool, ((char **)arr->elts)[((arr->nelts)-1)]));
+            rpaf_client_addr(r->connection)->sa.sin.sin_addr.s_addr = apr_inet_addr(remote_ip);
             if (cfg->sethostname) {
                 const char *hostvalue;
                 if (hostvalue = apr_table_get(r->headers_in, "X-Forwarded-Host")) {
