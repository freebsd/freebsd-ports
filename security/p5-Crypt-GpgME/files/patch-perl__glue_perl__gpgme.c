The trustlist feature, which only worked for a short period in 2003, was
removed in GpgME 2.0.0.

--- perl_glue/perl_gpgme.c.orig	2008-04-30 04:10:10 UTC
+++ perl_glue/perl_gpgme.c
@@ -762,36 +762,6 @@ SV *
 }
 
 SV *
-perl_gpgme_hashref_from_trust_item (gpgme_trust_item_t item) {
-	SV *sv;
-	HV *hv;
-
-	hv = newHV ();
-
-	if (item->keyid) {
-		perl_gpgme_hv_store (hv, "keyid", 5, newSVpv (item->keyid, 0));
-	}
-
-	perl_gpgme_hv_store (hv, "type", 4, newSVpv (item->type == 1 ? "key" : "uid", 0));
-	perl_gpgme_hv_store (hv, "level", 5, newSViv (item->level));
-
-	if (item->type == 1 && item->owner_trust) {
-		perl_gpgme_hv_store (hv, "owner_trust", 11, newSVpv (item->owner_trust, 0));
-	}
-
-	if (item->validity) {
-		perl_gpgme_hv_store (hv, "validity", 8, newSVpv (item->validity, 0));
-	}
-
-	if (item->type == 2 && item->name) {
-		perl_gpgme_hv_store (hv, "name", 4, newSVpv (item->name, 0));
-	}
-
-	sv = newRV_noinc ((SV *)hv);
-	return sv;
-}
-
-SV *
 perl_gpgme_sv_from_status_code (gpgme_status_code_t status) {
 	int i;
 	SV *ret = NULL;
