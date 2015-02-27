--- lib/krb5/crypto-rand.c.orig	2012-12-09 23:06:44.000000000 +0100
+++ lib/krb5/crypto-rand.c	2015-02-27 22:45:22.415756347 +0100
@@ -70,8 +70,6 @@
 	if (!krb5_init_context(&context)) {
 	    p = krb5_config_get_string(context, NULL, "libdefaults",
 				       "egd_socket", NULL);
-	    if (p != NULL)
-		RAND_egd_bytes(p, ENTROPY_NEEDED);
 	    krb5_free_context(context);
 	}
 #else
