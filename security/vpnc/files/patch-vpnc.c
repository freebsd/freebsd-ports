--- vpnc.c.orig	Tue Dec 16 00:25:01 2003
+++ vpnc.c	Tue Dec 16 00:25:33 2003
@@ -2007,7 +2007,7 @@
     else
       read_config_file (argv[i], config, 0);
 
-  read_config_file ("/etc/vpnc.conf", config, 1);
+  read_config_file ("%%PREFIX%%/etc/vpnc.conf", config, 1);
 
   if (!config[CONFIG_IKE_DH])
     config[CONFIG_IKE_DH] = "dh2";
