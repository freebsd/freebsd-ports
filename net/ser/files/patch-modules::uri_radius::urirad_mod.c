
$FreeBSD$

--- modules/uri_radius/urirad_mod.c.orig	Mon Jul 19 01:56:24 2004
+++ modules/uri_radius/urirad_mod.c	Tue Jul 27 21:01:37 2004
@@ -51,7 +51,7 @@
 /*
  * Module parameter variables
  */
-static char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+static char* radius_config = (CFG_DIR "radiusclient.conf");
 static int service_type = -1;
 
 /*
