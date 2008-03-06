--- config.c.orig	2008-03-06 17:03:57.000000000 +0100
+++ config.c	2008-03-06 17:14:29.000000000 +0100
@@ -257,17 +257,36 @@
 
 static const char *config_def_app_version(void)
 {
-	struct utsname uts;
-	char *version;
+        char *version;
+#ifndef CISCO_PATCH_VERSION
+        struct utsname uts;
 
-	uname(&uts);
-	asprintf(&version, "Cisco Systems VPN Client %s:%s", VERSION, uts.sysname);
-	return version;
+        uname(&uts);
+#endif
+
+#ifdef CISCO_PATCH_VERSION
+        /*
+         * Raffaele De Lorenzo March 2008
+         * Some Cisco Concentrator refuse connection if the Presentation Version
+         * String is not the same like Official "Cisco VPN Client". This patch
+         * masked the version to "Cisco Systems VPN Client 4.8.00 (0490):Linux",
+         */
+#define CISCO_CONC_PRESENT_VERSION      "Cisco Systems VPN Client 4.8.00 (0490):Linux"
+#endif
+
+        asprintf(&version,
+#ifdef CISCO_PATCH_VERSION
+                CISCO_CONC_PRESENT_VERSION
+#else
+                "Cisco Systems VPN Client %s:%s", VERSION, uts.sysname
+#endif
+                );
+        return version;
 }
 
 static const char *config_def_script(void)
 {
-	return "/etc/vpnc/vpnc-script";
+	return "%%PREFIX%%/sbin/vpnc-script";
 }
 
 static const char *config_def_pid_file(void)
@@ -538,7 +557,7 @@
 {
 	char *realname;
 	
-	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
+	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "%%PREFIX%%/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
 	return realname;
 }
 
@@ -757,8 +776,8 @@
 	}
 	
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc/default.conf", config, 1);
+		read_config_file("%%PREFIX%%/etc/vpnc.conf", config, 1);
 	}
 	
 	if (!print_config) {
