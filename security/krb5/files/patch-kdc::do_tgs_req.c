diff -ur krb5-1.2.7/src/kdc/do_tgs_req.c krb5-1.2.7/src/kdc/do_tgs_req.c
--- kdc/do_tgs_req.c	2003-02-03 15:24:58.000000000 -0500
+++ kdc/do_tgs_req.c	2003-02-03 17:54:27.000000000 -0500
@@ -180,7 +180,7 @@
 		krb5_data *tgs_1 =
 		    krb5_princ_component(kdc_context, tgs_server, 1);

-		if (server_1->length != tgs_1->length ||
+		if (!tgs_1 || server_1->length != tgs_1->length ||
 		    memcmp(server_1->data, tgs_1->data, tgs_1->length)) {
 		    krb5_db_free_principal(kdc_context, &server, nprincs);
 		    find_alternate_tgs(request, &server, &more, &nprincs);
