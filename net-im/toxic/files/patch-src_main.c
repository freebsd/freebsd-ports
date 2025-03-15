--- src/main.c.orig	2025-01-09 14:41:43 UTC
+++ src/main.c
@@ -477,7 +477,7 @@ static void init_tox_options(const Run_Options *run_op
     tox_options_set_tcp_port(tox_opts, run_opts->tcp_port);
     tox_options_set_local_discovery_enabled(tox_opts, !run_opts->disable_local_discovery);
     tox_options_set_experimental_groups_persistence(tox_opts, true);
-    tox_options_set_experimental_disable_dns(tox_opts, false);
+    // tox_options_set_experimental_disable_dns(tox_opts, false);
 
     if (run_opts->logging) {
         tox_options_set_log_callback(tox_opts, cb_toxcore_logger);
@@ -508,9 +508,10 @@ static void init_tox_options(const Run_Options *run_op
     }
 
     if (!tox_options_get_udp_enabled(tox_opts)) {
+	/*
         if (proxy_set) {
             tox_options_set_experimental_disable_dns(tox_opts, true);
-        }
+        }	*/
 
         init_queue_add(init_q, "UDP disabled");
     } else if (proxy_set) {
