diff -ur krb5-1.2.7/src/lib/krb5/krb/gc_frm_kdc.c krb5-1.2.7/src/lib/krb5/krb/gc_frm_kdc.c
--- lib/krb5/krb/gc_frm_kdc.c	1999-09-24 17:19:24.000000000 -0400
+++ lib/krb5/krb/gc_frm_kdc.c	2003-02-03 17:35:40.000000000 -0500
@@ -347,7 +347,9 @@
 	for (next_server = top_server; *next_server; next_server++) {
             krb5_data *realm_1 = krb5_princ_component(context, next_server[0], 1);
             krb5_data *realm_2 = krb5_princ_component(context, tgtr->server, 1);
-            if (realm_1->length == realm_2->length &&
+	    if (realm_1 != NULL &&
+		realm_2 != NULL &&
+                realm_1->length == realm_2->length &&
                 !memcmp(realm_1->data, realm_2->data, realm_1->length)) {
 		break;
             }
