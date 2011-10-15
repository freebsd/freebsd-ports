--- ./src/providers/krb5/krb5_utils.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/krb5/krb5_utils.c	2011-10-13 12:15:03.000000000 -0400
@@ -435,10 +435,10 @@
     }
 
     server_name = talloc_asprintf(NULL, "krbtgt/%.*s@%.*s",
-                                  krb5_princ_realm(ctx, client_princ)->length,
-                                  krb5_princ_realm(ctx, client_princ)->data,
-                                  krb5_princ_realm(ctx, client_princ)->length,
-                                  krb5_princ_realm(ctx, client_princ)->data);
+                                  krb5_realm_length(krb5_princ_realm(ctx, client_princ)),
+                                  krb5_princ_realm(ctx, client_princ),
+                                  krb5_realm_length(krb5_princ_realm(ctx, client_princ)),
+                                  krb5_princ_realm(ctx, client_princ));
     if (server_name == NULL) {
         kerr = KRB5_CC_NOMEM;
         DEBUG(1, ("talloc_asprintf failed.\n"));
