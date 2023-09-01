--- daemon/analytics.c.orig	2023-08-09 18:44:44.805963000 +0000
+++ daemon/analytics.c	2023-08-09 19:09:09.490652000 +0000
@@ -831,6 +831,12 @@
         setenv("NETDATA_UPDATE_EVERY", b, 1);
     }
 
+    netdata_log_error("NETDATA_CACHE_DIR: %s", netdata_configured_cache_dir);
+    netdata_log_error("NETDATA_LIB_DIR: %s", netdata_configured_varlib_dir);
+    netdata_log_error("NETDATA_LOCK_DIR: %s", netdata_configured_lock_dir);
+    netdata_log_error("NETDATA_LOG_DIR: %s", netdata_configured_log_dir);
+    netdata_log_error("HOME: %s", netdata_configured_home_dir);
+
     setenv("NETDATA_VERSION", program_version, 1);
     setenv("NETDATA_HOSTNAME", netdata_configured_hostname, 1);
     setenv("NETDATA_CONFIG_DIR", verify_required_directory(netdata_configured_user_config_dir), 1);
