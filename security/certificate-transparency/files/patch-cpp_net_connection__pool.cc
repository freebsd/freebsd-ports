--- cpp/net/connection_pool.cc.orig	2018-01-04 08:45:06 UTC
+++ cpp/net/connection_pool.cc
@@ -454,12 +454,12 @@ unique_ptr<ConnectionPool::Connection> ConnectionPool:
                                     kZeroMillis};
     evhtp_connection_set_timeouts(handle->connection(), &read_timeout,
                                   &write_timeout);
-    evhtp_set_hook(&handle->connection()->hooks, evhtp_hook_on_conn_error,
+    evhtp_connection_set_hook(handle->connection(), evhtp_hook_on_conn_error,
                    reinterpret_cast<evhtp_hook>(
                        EvConnection::ConnectionErrorHook),
                    reinterpret_cast<void*>(conn.get()));
-    evhtp_set_hook(
-        &handle->connection()->hooks, evhtp_hook_on_connection_fini,
+    evhtp_connection_set_hook(
+        handle->connection(), evhtp_hook_on_connection_fini,
         reinterpret_cast<evhtp_hook>(EvConnection::ConnectionFinishedHook),
         // We'll hold on to another shared_ptr to the Connection
         // until evhtp tells us that it's finished with the cnxn.
