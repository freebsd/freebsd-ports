--- client/clparse.c.orig	Wed May 10 02:20:11 2000
+++ client/clparse.c	Wed May 10 02:20:31 2000
@@ -74,7 +74,7 @@
 	top_level_config.backoff_cutoff = 15;
 	top_level_config.initial_interval = 3;
 	top_level_config.bootp_policy = P_ACCEPT;
-	top_level_config.script_name = "/etc/dhclient-script";
+	top_level_config.script_name = CL_DEFAULT_SCRIPT_NAME;
 	top_level_config.requested_options = default_requested_options;
 
 	top_level_config.on_receipt = new_group ("read_client_conf");
