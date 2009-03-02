--- libraries/libldap/tls_o.c	2009/02/10 12:27:22	1.6
+++ libraries/libldap/tls_o.c	2009/03/02 16:43:38	1.7
@@ -421,7 +421,7 @@
 	xn = X509_get_subject_name(x);
 	der_dn->bv_len = i2d_X509_NAME( xn, NULL );
 	der_dn->bv_val = xn->bytes->data;
-	X509_free(x);
+	/* Don't X509_free, the session is still using it */
 	return 0;
 }
 
