
$FreeBSD$

--- modules/auth_radius/authrad_mod.c.orig
+++ modules/auth_radius/authrad_mod.c
@@ -69,7 +69,7 @@
 /*
  * Module parameter variables
  */
-static char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+static char* radius_config = (CFG_DIR "radiusclient.conf");
 static int service_type = -1;
 
 
