
$FreeBSD$

--- modules/auth_radius/authrad_mod.c.orig	Mon Jul 19 01:56:23 2004
+++ modules/auth_radius/authrad_mod.c	Tue Jul 27 21:50:52 2004
@@ -64,7 +64,7 @@
 /*
  * Module parameter variables
  */
-static char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+static char* radius_config = (CFG_DIR "radiusclient.conf");
 static int service_type = -1;
 
 
