https://www.apache.org/dist/httpd/patches/apply_to_2.2.34/2.2.x-mod_proxy-without-APR_HAS_THREADS.patch

Index: modules/proxy/proxy_util.c
===================================================================
--- modules/proxy/proxy_util.c	(revision 1821521)
+++ modules/proxy/proxy_util.c	(working copy)
@@ -1398,7 +1398,6 @@ PROXY_DECLARE(proxy_worker *) ap_proxy_get_worker(
     return max_worker;
 }
 
-#if APR_HAS_THREADS
 static void socket_cleanup(proxy_conn_rec *conn)
 {
     conn->sock = NULL;
@@ -1407,6 +1406,7 @@ static void socket_cleanup(proxy_conn_rec *conn)
     apr_pool_clear(conn->scpool);
 }
 
+#if APR_HAS_THREADS
 static apr_status_t conn_pool_cleanup(void *theworker)
 {
     proxy_worker *worker = (proxy_worker *)theworker;
