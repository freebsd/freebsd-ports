--- config.c.orig	Sat May 14 13:20:11 2005
+++ config.c	Sat May 14 13:20:51 2005
@@ -520,8 +520,8 @@
 	}
 
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc.conf", config, 1);
 	}
 
 	if (!print_config) {
