--- libgupnp/gupnp-control-point.c.orig	2018-11-12 22:04:49 UTC
+++ libgupnp/gupnp-control-point.c
@@ -795,7 +795,7 @@ parse_usn (const char *usn,
         /* Count elements */
         count = g_strv_length (bits);
 
-        if (count == 1) {
+        if (count == 1 || (count == 2 && strlen(bits[1]) == 0)) {
                 /* uuid:device-UUID */
 
                 *udn = bits[0];
