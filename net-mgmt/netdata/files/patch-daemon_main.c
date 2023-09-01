--- daemon/main.c.orig	2023-08-09 19:47:06.833144000 +0000
+++ daemon/main.c	2023-08-09 19:47:43.035728000 +0000
@@ -1108,8 +1108,7 @@
     netdata_configured_web_dir          = config_get(CONFIG_SECTION_DIRECTORIES, "web",          netdata_configured_web_dir);
     netdata_configured_cache_dir        = config_get(CONFIG_SECTION_DIRECTORIES, "cache",        netdata_configured_cache_dir);
     netdata_configured_varlib_dir       = config_get(CONFIG_SECTION_DIRECTORIES, "lib",          netdata_configured_varlib_dir);
-    char *env_home=getenv("HOME");
-    netdata_configured_home_dir         = config_get(CONFIG_SECTION_DIRECTORIES, "home",         env_home?env_home:netdata_configured_home_dir);
+    netdata_configured_home_dir         = config_get(CONFIG_SECTION_DIRECTORIES, "home",         netdata_configured_home_dir);
 
     netdata_configured_lock_dir = initialize_lock_directory_path(netdata_configured_varlib_dir);
 
