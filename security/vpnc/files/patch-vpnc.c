--- vpnc.c.orig	Sun Apr 25 02:46:23 2004
+++ vpnc.c	Sun Apr 25 02:46:50 2004
@@ -2036,8 +2036,8 @@
     else
       read_config_file (argv[i], config, 0);
 
-  read_config_file ("/etc/vpnc/default.conf", config, 1);
-  read_config_file ("/etc/vpnc.conf", config, 1);
+  read_config_file ("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+  read_config_file ("%%PREFIX%%/etc/vpnc.conf", config, 1);
 
   if (!print_config) {
     if (!config[CONFIG_IKE_DH])
