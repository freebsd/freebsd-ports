--- src/net/asio.cpp.orig	2019-04-14 16:29:43 UTC
+++ src/net/asio.cpp
@@ -79,8 +79,12 @@ void connect(Endpoint const& endpoint, Socket& s, Yiel
   else
 #endif // BUILD_TEST
     asio::async_connect(s,
-                        tcp::resolver{s.get_executor().context()}.async_resolve(
-                            endpoint.host_, endpoint.port_, yield),
+                        tcp::resolver{s.get_executor()
+#ifndef RESOLVER_CONSTRUCTED_FROM_EXECUTOR
+                                          .context()
+#endif // RESOLVER_CONSTRUCTED_FROM_EXECUTOR
+                        }
+                            .async_resolve(endpoint.host_, endpoint.port_, yield),
                         yield);
 }
 
