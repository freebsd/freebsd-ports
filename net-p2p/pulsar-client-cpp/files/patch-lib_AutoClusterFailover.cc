--- lib/AutoClusterFailover.cc.orig	2026-04-17 06:16:08 UTC
+++ lib/AutoClusterFailover.cc
@@ -173,7 +173,7 @@ class AutoClusterFailoverImpl : public std::enable_sha
         ASIO_ERROR ignored;
         context->resolver.cancel();
         context->socket.close(ignored);
-        context->timer.cancel(ignored);
+        context->timer.cancel();
 
         context->callback(success);
     }
