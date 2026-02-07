The trustlist feature, which only worked for a short period in 2003, was
removed in GpgME 2.0.0.

--- xs/GpgME.xs.orig	2008-04-30 04:10:27 UTC
+++ xs/GpgME.xs
@@ -453,29 +453,6 @@ gpgme_keylist (ctx, pattern, secret_only=0)
 			perl_gpgme_assert_error (err);
 		}
 
-void
-gpgme_trustlist (ctx, pattern, max_level)
-		gpgme_ctx_t ctx
-		const char *pattern
-		int max_level
-	PREINIT:
-		gpgme_error_t err;
-		gpgme_trust_item_t item;
-	PPCODE:
-		err = gpgme_op_trustlist_start (ctx, pattern, max_level);
-		perl_gpgme_assert_error (err);
-
-		while ((err = gpgme_op_trustlist_next (ctx, &item)) == GPG_ERR_NO_ERROR) {
-			XPUSHs (perl_gpgme_hashref_from_trust_item (item));
-			gpgme_trust_item_unref (item);
-		}
-
-		if (gpg_err_code (err) != GPG_ERR_EOF) {
-			perl_gpgme_assert_error (err);
-		}
-
-		gpgme_op_trustlist_end (ctx);
-
 NO_OUTPUT gpgme_error_t
 gpgme_engine_check_version (ctx, proto)
 		perl_gpgme_ctx_or_null_t ctx
