--- xioopts.c.orig	2015-01-24 10:15:22 UTC
+++ xioopts.c
@@ -296,7 +296,7 @@ const struct optname optionnames[] = {
 #if WITH_EXT2 && defined(EXT2_COMPR_FL)
 	IF_ANY    ("compr",	&opt_ext2_compr)
 #endif
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 	IF_OPENSSL("compress",	&opt_openssl_compress)
 #endif
 #ifdef TCP_CONN_ABORT_THRESHOLD  /* HP_UX */
@@ -1098,7 +1098,7 @@ const struct optname optionnames[] = {
 	IF_OPENSSL("openssl-certificate",	&opt_openssl_certificate)
 	IF_OPENSSL("openssl-cipherlist",	&opt_openssl_cipherlist)
 	IF_OPENSSL("openssl-commonname",	&opt_openssl_commonname)
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 	IF_OPENSSL("openssl-compress",	&opt_openssl_compress)
 #endif
 	IF_OPENSSL("openssl-dhparam",	&opt_openssl_dhparam)
