--- vpnc.c.dist	Mon May  3 14:13:05 2004
+++ vpnc.c	Mon May  3 14:13:41 2004
@@ -2162,8 +2162,8 @@
     else
       read_config_file (argv[i], config, 0);
 
-  read_config_file ("/etc/vpnc/default.conf", config, 1);
-  read_config_file ("/etc/vpnc.conf", config, 1);
+  read_config_file ("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+  read_config_file ("%%PREFIX%%/etc/vpnc.conf", config, 1);
 
   if (!print_config) {
     if (!config[CONFIG_IKE_DH])
