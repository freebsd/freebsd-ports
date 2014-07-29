
$FreeBSD$

--- modules/group_radius/grouprad_mod.c.orig
+++ modules/group_radius/grouprad_mod.c
@@ -57,7 +57,7 @@
 /*
  * Module parameter variables
  */
-static char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+static char* radius_config = (CFG_DIR "radiusclient.conf");
 int use_domain = 0;  /* By default we use domain */
 
 
