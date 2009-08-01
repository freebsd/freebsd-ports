--- libseahorse/seahorse-pgp-operation.c.orig	2009-08-01 15:26:28.000000000 -0400
+++ libseahorse/seahorse-pgp-operation.c	2009-08-01 15:23:41.000000000 -0400
@@ -323,6 +323,7 @@ seahorse_pgp_operation_init (SeahorsePGP
     gpgme_error_t err;
     gpgme_ctx_t ctx;
  
+    gpgme_check_version (NULL);
     err = gpgme_engine_check_version (proto);
     g_return_if_fail (GPG_IS_OK (err));
    
