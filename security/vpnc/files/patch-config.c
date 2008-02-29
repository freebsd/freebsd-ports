--- config.c.orig	2007-09-10 22:39:48.000000000 +0200
+++ config.c	2008-02-26 11:33:02.000000000 +0100
@@ -267,12 +267,12 @@
 
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
 
 static const char *config_def_vendor(void)
@@ -538,7 +538,7 @@
 {
 	char *realname;
 	
-	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
+	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "%%PREFIX%%/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
 	return realname;
 }
 
@@ -757,8 +757,8 @@
 	}
 	
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc.conf", config, 1);
 	}
 	
 	if (!print_config) {
