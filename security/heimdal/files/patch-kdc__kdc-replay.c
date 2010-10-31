--- kdc/kdc-replay.c.orig	2010-10-16 16:43:39.000000000 +0200
+++ kdc/kdc-replay.c	2010-10-16 16:45:24.000000000 +0200
@@ -86,6 +86,7 @@
     if (ret)
 	krb5_err(context, 1, ret, "krb5_kdc_set_dbinfo");
 
+#ifdef PKINIT
     if (config->enable_pkinit) {
 	if (config->pkinit_kdc_identity == NULL)
 	    krb5_errx(context, 1, "pkinit enabled but no identity");
@@ -100,6 +101,7 @@
 			       config->pkinit_kdc_revoke);
 
     }
+#endif /* PKINIT */
 
     if (argc != 2)
 	errx(1, "argc != 2");
