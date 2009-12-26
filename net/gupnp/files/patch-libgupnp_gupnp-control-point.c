--- libgupnp/gupnp-control-point.c.orig	2009-08-24 18:29:33.000000000 +0200
+++ libgupnp/gupnp-control-point.c	2009-12-26 14:32:06.000000000 +0100
@@ -658,7 +658,7 @@
         /* Count elements */
         count = g_strv_length (bits);
 
-        if (count == 1) {
+        if (count == 1 || (count == 2 && strlen(bits[1]) == 0)) {
                 /* uuid:device-UUID */
 
                 *udn = bits[0];
