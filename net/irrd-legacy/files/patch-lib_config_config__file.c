--- lib/config/config_file.c.orig	2015-04-03 11:26:26 UTC
+++ lib/config/config_file.c
@@ -772,7 +772,7 @@ config_line_address (uii_connection_t * uii, prefix_t 
 	Deref_Prefix (prefix);
         return (1);
     }
-    if (prefix_compare2 (UII->prefix, prefix) != 0) {
+    if ( UII->prefix == NULL || prefix_compare2 (UII->prefix, prefix) != 0) {
     	set_uii (UII, UII_ADDR, prefix, 0);
 	listen_uii2 (NULL);
     }
