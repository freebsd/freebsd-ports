
$FreeBSD$

--- modules/group_radius/grouprad_mod.c	2003/07/06 18:04:54	1.1
+++ modules/group_radius/grouprad_mod.c	2003/07/06 18:05:41
@@ -52,7 +52,7 @@
 /*
  * Module parameter variables
  */
-char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+char* radius_config = (CFG_DIR "radiusclient.conf");
 int use_domain = 1;  /* By default we use domain */
 
 
