-- Run the libuv loop directly for libwebsockets 5.1 compatibility.
-- libwebsockets 5.1 changed lws_service() on libuv to run a single loop turn
-- (UV_RUN_ONCE) instead of blocking until the loop is stopped, so ttyd exits
-- right after printing "Listening on port".  Since ttyd owns the foreign loop,
-- run it directly with uv_run(UV_RUN_DEFAULT), which restores the pre-5.1
-- blocking behaviour and keeps the existing uv_stop() / signal-driven exit
-- behaviour.
-- Reference: https://github.com/tsl0922/ttyd/pull/1589

--- src/server.c.orig	2024-10-10 09:00:00 UTC
+++ src/server.c
@@ -608,7 +608,7 @@
   for (int i = 0; i < sig_count; i++) {
     uv_signal_start(&signals[i], signal_cb, sig_nums[i]);
   }

-  lws_service(context, 0);
+  uv_run(server->loop, UV_RUN_DEFAULT);

   for (int i = 0; i < sig_count; i++) {
     uv_signal_stop(&signals[i]);
