
$FreeBSD$

--- modules/uri_radius/urirad_mod.c	2003/07/06 18:04:54	1.1
+++ modules/uri_radius/urirad_mod.c	2003/07/06 18:05:59
@@ -48,7 +48,7 @@
 /*
  * Module parameter variables
  */
-char* radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+char* radius_config = (CFG_DIR "radiusclient.conf");
 int service_type = PW_CALL_CHECK;
 
 /*
