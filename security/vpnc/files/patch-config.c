--- config.c.orig	Sun May  1 22:06:36 2005
+++ config.c	Tue Aug  2 20:18:29 2005
@@ -125,12 +125,12 @@
 
 static const char *config_def_script(void)
 {
-	return "/etc/vpnc/vpnc-script";
+	return "%%PREFIX%%/sbin/vpnc-script";
 }
 
 static const char *config_def_pid_file(void)
 {
-	return "/var/run/vpnc/pid";
+	return "/var/run/vpnc.pid";
 }
 
 static const struct config_names_s {
@@ -520,8 +520,8 @@
 	}
 
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc.conf", config, 1);
 	}
 
 	if (!print_config) {
