Index: kdc/kdc_preauth.c
=====================================================================
RCS file: /cvs/krbdev/krb5/src/kdc/kdc_preauth.c,v
retrieving revision 5.30
diff -u -r5.30 kdc_preauth.c
--- kdc/kdc_preauth.c	2001/06/21 13:46:15	5.30
+++ kdc/kdc_preauth.c	2002/06/24 22:28:01
@@ -543,7 +543,7 @@
     while (1) {
 	retval = krb5_dbe_search_enctype(context, client, &start, -1,
 					 -1, 0, &client_key);
-	if (retval == ENOENT)
+	if (retval == KRB5_KDB_NO_MATCHING_KEY)
 	    break;
 	if (retval)
 	    goto cleanup;
