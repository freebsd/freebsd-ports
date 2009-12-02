
$FreeBSD$

--- main.cpp.orig
+++ main.cpp
@@ -97,11 +97,11 @@
 	
 	string cf_network_addr				= arguments.get("a", config.get("network_addr", "0.0.0.0"));
 	string cf_network_port				= arguments.get("p", config.get("network_port", "5109"));
-	string cf_server_user				= arguments.get("u", config.get("server_user", "istat"));
-	string cf_server_group				= arguments.get("g", config.get("server_group", "istat"));
-	string cf_server_pid					= arguments.get("pid", config.get("server_pid", "/var/run/istat/istatd.pid"));
+	string cf_server_user				= arguments.get("u", config.get("server_user", "nobody"));
+	string cf_server_group				= arguments.get("g", config.get("server_group", "nobody"));
+	string cf_server_pid					= arguments.get("pid", config.get("server_pid", "/var/run/istatd.pid"));
 	string cf_server_socket				= arguments.get("socket", config.get("server_socket", "/tmp/istatd.sock"));
-	string cf_cache_dir					= arguments.get("cache", config.get("cache_dir", "/var/cache/istat"));
+	string cf_cache_dir					= arguments.get("cache", config.get("cache_dir", "/var/db/istatd"));
    
 #ifdef HAVE_LIBKSTAT
 	if(-1 == kstat_init()) return 1;
