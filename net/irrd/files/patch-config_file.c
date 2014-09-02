--- lib/config/config_file.c.orig	2009-03-25 00:38:11.000000000 +0300
+++ lib/config/config_file.c	2011-06-24 17:09:08.000000000 +0400
@@ -772,7 +772,7 @@
 	Deref_Prefix (prefix);
         return (1);
     }
-    if (prefix_compare2 (UII->prefix, prefix) != 0) {
+    if ( UII->prefix == NULL || prefix_compare2 (UII->prefix, prefix) != 0) {
     	set_uii (UII, UII_ADDR, prefix, 0);
 	listen_uii2 (NULL);
     }
