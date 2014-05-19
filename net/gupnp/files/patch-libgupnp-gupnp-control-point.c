--- libgupnp/gupnp-control-point.c.orig	2012-11-29 07:13:43.000000000 +0800
+++ libgupnp/gupnp-control-point.c	2013-03-15 16:00:16.921426942 +0800
@@ -692,7 +692,7 @@
         /* Count elements */
         count = g_strv_length (bits);
 
-        if (count == 1) {
+        if (count == 1 || (count == 2 && strlen(bits[1]) == 0)) {
                 /* uuid:device-UUID */
 
                 *udn = bits[0];
