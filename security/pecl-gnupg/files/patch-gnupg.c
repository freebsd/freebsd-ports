The trustlist feature has been deprecated in Gpgme since 2003 and was removed
in version 2.0.0.

--- gnupg.c.orig	2025-06-02 18:54:02 UTC
+++ gnupg.c
@@ -341,7 +341,9 @@ phpc_function_entry gnupg_methods[] = {
 	PHP_GNUPG_FALIAS(addencryptkey,     arginfo_gnupg_key_method)
 	PHP_GNUPG_FALIAS(adddecryptkey,     arginfo_gnupg_key_passphrase_method)
 	PHP_GNUPG_FALIAS(deletekey,         arginfo_gnupg_deletekey_method)
+#if GPGME_VERSION_NUMBER < 0x020000  /* GPGME < 2.0.0 */
 	PHP_GNUPG_FALIAS(gettrustlist,      arginfo_gnupg_pattern_method)
+#endif
 	PHP_GNUPG_FALIAS(listsignatures,    arginfo_gnupg_keyid_method)
 	PHP_GNUPG_FALIAS(seterrormode,      arginfo_gnupg_errmode_method)
 	PHPC_FE_END
@@ -483,7 +485,9 @@ static zend_function_entry gnupg_functions[] = {
 	PHP_FE(gnupg_addencryptkey,		arginfo_gnupg_key_function)
 	PHP_FE(gnupg_adddecryptkey,		arginfo_gnupg_key_passphrase_function)
 	PHP_FE(gnupg_deletekey,			arginfo_gnupg_deletekey_function)
+#if GPGME_VERSION_NUMBER < 0x020000  /* GPGME < 2.0.0 */
 	PHP_FE(gnupg_gettrustlist,		arginfo_gnupg_pattern_function)
+#endif
 	PHP_FE(gnupg_listsignatures,	arginfo_gnupg_keyid_function)
 	PHP_FE(gnupg_seterrormode,		arginfo_gnupg_errmode_function)
 	PHPC_FE_END
@@ -1936,6 +1940,7 @@ PHP_FUNCTION(gnupg_deletekey)
 }
 /* }}} */
 
+#if GPGME_VERSION_NUMBER < 0x020000  /* GPGME < 2.0.0 */
 /* {{{ proto array gnupg_gettrustlist(string pattern)
 * searching for trust items which match PATTERN
 */
@@ -1980,6 +1985,7 @@ PHP_FUNCTION(gnupg_gettrustlist)
 	}
 }
 /* }}} */
+#endif
 
 /* {{{ proto array gnupg_listsignatures(string keyid) */
 PHP_FUNCTION(gnupg_listsignatures)
