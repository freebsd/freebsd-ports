--- src/address-book-config.c.orig	Thu Jun 20 00:18:24 2002
+++ src/address-book-config.c	Thu Jun 20 00:16:15 2002
@@ -576,7 +576,7 @@
 	create_entry(mcw, table, NULL, NULL, 1, 
 		     ab ? ab->host : host, label);
 
-    label = create_label(_("_Base Domain Name"), table, 2, label);
+    label = create_label(_("_Base Domain Name"), table, 2);
     abc->ab_specific.ldap.base_dn = 
 	create_entry(mcw, table, NULL, NULL, 2, 
 		     ab ? ab->base_dn : base, label);
