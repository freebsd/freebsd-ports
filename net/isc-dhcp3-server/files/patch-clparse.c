--- client/clparse.c.orig	Thu Jan 25 09:17:17 2001
+++ client/clparse.c	Fri Jan 26 06:11:01 2001
@@ -50,7 +50,7 @@
 
 static TIME parsed_time;
 
-char client_script_name [] = "/etc/dhclient-script";
+const char *client_script_name = CL_DEFAULT_SCRIPT_NAME;
 
 struct client_config top_level_config;
 
