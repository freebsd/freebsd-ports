Index: kdc/kdc_util.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/kdc/kdc_util.c,v
retrieving revision 5.96.2.2.2.3
diff -p -u -r5.96.2.2.2.3 kdc_util.c
--- kdc/kdc_util.c	2002/10/31 00:38:34	5.96.2.2.2.3
+++ kdc/kdc_util.c	2003/03/19 00:39:00
@@ -157,7 +157,8 @@ realm_compare(princ1, princ2)
 krb5_boolean krb5_is_tgs_principal(principal)
 	krb5_principal	principal;
 {
-	if ((krb5_princ_component(kdc_context, principal, 0)->length ==
+	if (krb5_princ_size(kdc_context, principal) > 0 &&
+	    (krb5_princ_component(kdc_context, principal, 0)->length ==
 	     KRB5_TGS_NAME_SIZE) &&
 	    (!memcmp(krb5_princ_component(kdc_context, principal, 0)->data,
 		     KRB5_TGS_NAME, KRB5_TGS_NAME_SIZE)))
@@ -1195,7 +1196,8 @@
 	    return KRB_AP_ERR_NOT_US;
 	}
 	/* ...and that the second component matches the server realm... */
-	if ((krb5_princ_component(kdc_context, ticket->server, 1)->length !=
+	if ((krb5_princ_size(kdc_context, ticket->server) <= 1) ||
+	    (krb5_princ_component(kdc_context, ticket->server, 1)->length !=
 	     krb5_princ_realm(kdc_context, request->server)->length) ||
 	    memcmp(krb5_princ_component(kdc_context, ticket->server, 1)->data,
 		   krb5_princ_realm(kdc_context, request->server)->data,
