--- src/Cedar/Server.c.orig	2014-06-08 06:19:15 UTC
+++ src/Cedar/Server.c
@@ -115,12 +115,12 @@
 
 static SERVER *server = NULL;
 static LOCK *server_lock = NULL;
-char *SERVER_CONFIG_FILE_NAME = "@vpn_server.config";
-char *SERVER_CONFIG_FILE_NAME_IN_CLIENT = "@vpn_gate_svc.config";
-char *SERVER_CONFIG_FILE_NAME_IN_CLIENT_RELAY = "@vpn_gate_relay.config";
-char *BRIDGE_CONFIG_FILE_NAME = "@vpn_bridge.config";
-char *SERVER_CONFIG_TEMPLATE_NAME = "@vpn_server_template.config";
-char *BRIDGE_CONFIG_TEMPLATE_NAME = "@vpn_server_template.config";
+char *SERVER_CONFIG_FILE_NAME = "/var/db/softether/vpn_server.config";
+char *SERVER_CONFIG_FILE_NAME_IN_CLIENT = "/var/db/softether/vpn_gate_svc.config";
+char *SERVER_CONFIG_FILE_NAME_IN_CLIENT_RELAY = "/var/db/softether/vpn_gate_relay.config";
+char *BRIDGE_CONFIG_FILE_NAME = "/var/db/softether/vpn_bridge.config";
+char *SERVER_CONFIG_TEMPLATE_NAME = "/var/db/softether/vpn_server_template.config";
+char *BRIDGE_CONFIG_TEMPLATE_NAME = "/var/db/softether/vpn_server_template.config";
 
 static bool server_reset_setting = false;
 
