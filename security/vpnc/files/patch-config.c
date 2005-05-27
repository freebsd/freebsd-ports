--- config.c.bak	Sun May 15 15:06:20 2005
+++ config.c	Sun May 15 15:06:52 2005
@@ -125,7 +125,7 @@
 
 static const char *config_def_script(void)
 {
-	return "/etc/vpnc/vpnc-script";
+	return "%%PREFIX%%/sbin/vpnc-script";
 }
 
 static const char *config_def_pid_file(void)
@@ -520,8 +520,8 @@
 	}
 
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc.conf", config, 1);
 	}
 
 	if (!print_config) {
