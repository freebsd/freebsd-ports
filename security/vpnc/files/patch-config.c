--- config.c.orig	Fri Feb 16 18:22:06 2007
+++ config.c	Tue Mar 13 16:11:53 2007
@@ -251,12 +251,12 @@
 
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
@@ -485,7 +485,7 @@
 {
 	char *realname;
 	
-	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
+	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "%%PREFIX%%/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
 	return realname;
 }
 
@@ -701,8 +701,8 @@
 	}
 	
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc.conf", config, 1);
 	}
 	
 	if (!print_config) {
