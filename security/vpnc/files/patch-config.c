--- config.c.dist	Wed Nov 17 15:07:24 2004
+++ config.c	Wed Nov 17 15:07:33 2004
@@ -479,8 +479,8 @@
 		}
 	}
 
-	read_config_file("/etc/vpnc/default.conf", config, 1);
-	read_config_file("/etc/vpnc.conf", config, 1);
+	read_config_file("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+	read_config_file("%%PREFIX%%/etc/vpnc.conf", config, 1);
 
 	if (!print_config) {
 		for (i = 0; config_names[i].name != NULL; i++)
