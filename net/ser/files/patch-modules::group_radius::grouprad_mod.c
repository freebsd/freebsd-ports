
$FreeBSD$

--- modules/group_radius/grouprad_mod.c.orig	Mon Jul 19 01:56:24 2004
+++ modules/group_radius/grouprad_mod.c	Tue Jul 27 21:01:37 2004
@@ -57,7 +57,7 @@
 /*
  * Module parameter variables
  */
-static char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+static char* radius_config = (CFG_DIR "radiusclient.conf");
 int use_domain = 1;  /* By default we use domain */
 
 
