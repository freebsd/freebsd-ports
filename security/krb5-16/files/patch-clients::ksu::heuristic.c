diff -ur krb5-1.2.7/src/clients/ksu/heuristic.c krb5-1.2.7/src/clients/ksu/heuristic.c
--- clients/ksu/heuristic.c	2003-02-03 15:24:57.000000000 -0500
+++ clients/ksu/heuristic.c	2003-02-03 17:56:38.000000000 -0500
@@ -355,7 +355,7 @@
 		krb5_data *p2 =
 		    krb5_princ_component(context, temp_client, j);

-		if ((p1->length != p2->length) ||
+		if (!p1 || !p2 || (p1->length != p2->length) ||
 		    memcmp(p1->data,p2->data,p1->length)){
 		    got_one = FALSE;
 		    break;
