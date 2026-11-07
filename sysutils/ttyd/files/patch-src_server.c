--- src/server.c.orig	2024-03-30 03:04:51 UTC
+++ src/server.c
@@ -608,7 +608,9 @@ int main(int argc, char **argv) {
     uv_signal_start(&signals[i], signal_cb, sig_nums[i]);
   }
 
-  lws_service(context, 0);
+  // libwebsockets is a guest on our uv loop, so run the loop ourselves until signal_cb() stops it:
+  // since libwebsockets 5.1.0, lws_service() returns after a single loop turn instead of running it.
+  uv_run(server->loop, UV_RUN_DEFAULT);
 
   for (int i = 0; i < sig_count; i++) {
     uv_signal_stop(&signals[i]);
