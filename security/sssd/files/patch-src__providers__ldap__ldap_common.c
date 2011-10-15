--- ./src/providers/ldap/ldap_common.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/ldap/ldap_common.c	2011-10-13 12:15:03.000000000 -0400
@@ -749,7 +749,7 @@
     }
 
     realm = talloc_strdup(mem_ctx, krb5_realm);
-    krb5_free_default_realm(context, krb5_realm);
+    free(krb5_realm);
     if (!realm) {
         DEBUG(0, ("Out of memory\n"));
         goto done;
