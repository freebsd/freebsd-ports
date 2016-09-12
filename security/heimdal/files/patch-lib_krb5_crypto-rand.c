--- lib/krb5/crypto-rand.c.orig	2012-12-09 22:06:44 UTC
+++ lib/krb5/crypto-rand.c
@@ -70,8 +70,10 @@ seed_something(void)
 	if (!krb5_init_context(&context)) {
 	    p = krb5_config_get_string(context, NULL, "libdefaults",
 				       "egd_socket", NULL);
+# ifndef OPENSSL_NO_EGD
 	    if (p != NULL)
 		RAND_egd_bytes(p, ENTROPY_NEEDED);
+# endif
 	    krb5_free_context(context);
 	}
 #else
