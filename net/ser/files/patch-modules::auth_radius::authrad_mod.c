
$FreeBSD$

--- modules/auth_radius/authrad_mod.c	2004/02/05 19:49:04	1.1
+++ modules/auth_radius/authrad_mod.c	2004/02/05 19:49:21
@@ -59,7 +59,7 @@
 /*
  * Module parameter variables
  */
-char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+char* radius_config = (CFG_DIR "radiusclient.conf");
 int service_type = PW_SIP_SESSION;
 
 
