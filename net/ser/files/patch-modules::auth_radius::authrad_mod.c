
$FreeBSD$

--- modules/auth_radius/authrad_mod.c.orig	Sat May  3 00:36:29 2003
+++ modules/auth_radius/authrad_mod.c	Mon Sep  8 01:28:58 2003
@@ -59,7 +59,7 @@
 /*
  * Module parameter variables
  */
-char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+char* radius_config = (CFG_DIR "radiusclient.conf");
 int service_type = PW_SIP;
 
 
