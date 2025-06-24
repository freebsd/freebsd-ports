The trustlist feature, which only worked for a short period in 2003, was
removed in GpgME 2.0.0.

--- perl_glue/perl_gpgme.h.orig	2007-12-19 23:55:38 UTC
+++ perl_glue/perl_gpgme.h
@@ -117,8 +117,6 @@ SV *perl_gpgme_hash_algo_to_string (gpgme_hash_algo_t 
 
 SV *perl_gpgme_hash_algo_to_string (gpgme_hash_algo_t algo);
 
-SV *perl_gpgme_hashref_from_trust_item (gpgme_trust_item_t item);
-
 SV *perl_gpgme_sv_from_status_code (gpgme_status_code_t status);
 
 SV *perl_gpgme_genkey_result_to_sv (gpgme_genkey_result_t result);
