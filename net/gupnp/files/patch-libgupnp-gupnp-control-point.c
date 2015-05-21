--- libgupnp/gupnp-control-point.c.orig	2015-03-30 17:49:16 UTC
+++ libgupnp/gupnp-control-point.c
@@ -692,7 +692,7 @@ parse_usn (const char *usn,
         /* Count elements */
         count = g_strv_length (bits);
 
-        if (count == 1) {
+        if (count == 1 || (count == 2 && strlen(bits[1]) == 0)) {
                 /* uuid:device-UUID */
 
                 *udn = bits[0];
